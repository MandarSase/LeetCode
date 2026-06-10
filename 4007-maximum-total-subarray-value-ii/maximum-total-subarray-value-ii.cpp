class Solution {
public:
    using ll = long long;

    vector<vector<int>> stMax, stMin;
    vector<int> lg;

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        buildSparse(nums);

        auto getVal = [&](int l, int r) -> ll {
            int mx = queryMax(l, r);
            int mn = queryMin(l, r);
            return 1LL * mx - mn;
        };

        struct Node {
            long long val;
            int l, r;

            bool operator<(const Node& other) const {
                return val < other.val;
            }
        };

        priority_queue<Node> pq;

        for (int l = 0; l < n; l++) {
            pq.push({getVal(l, n - 1), l, n - 1});
        }

        long long ans = 0;

        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            if (r > l) {
                pq.push({getVal(l, r - 1), l, r - 1});
            }
        }

        return ans;
    }

private:
    void buildSparse(vector<int>& nums) {
        int n = nums.size();

        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        int K = lg[n] + 1;

        stMax.assign(K, vector<int>(n));
        stMin.assign(K, vector<int>(n));

        for (int i = 0; i < n; i++) {
            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }

        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[j][i] = max(
                    stMax[j - 1][i],
                    stMax[j - 1][i + (1 << (j - 1))]
                );

                stMin[j][i] = min(
                    stMin[j - 1][i],
                    stMin[j - 1][i + (1 << (j - 1))]
                );
            }
        }
    }

    int queryMax(int l, int r) {
        int j = lg[r - l + 1];
        return max(
            stMax[j][l],
            stMax[j][r - (1 << j) + 1]
        );
    }

    int queryMin(int l, int r) {
        int j = lg[r - l + 1];
        return min(
            stMin[j][l],
            stMin[j][r - (1 << j) + 1]
        );
    }
};