
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Construct Suffix Array
        vector<int> sa(n), rank(n), temp(n);

        iota(sa.begin(), sa.end(), 0);

        for (int i = 0; i < n; i++) {
            rank[i] = nums[i];
        }

        for (int k = 1; k < n; k *= 2) {

            sort(sa.begin(), sa.end(), [&](int a, int b) {

                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;

                return ra < rb;
            });

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {

                int a = sa[i - 1];
                int b = sa[i];

                pair<int, int> p1 = {
                    rank[a],
                    (a + k < n) ? rank[a + k] : -1
                };

                pair<int, int> p2 = {
                    rank[b],
                    (b + k < n) ? rank[b + k] : -1
                };

                temp[b] = temp[a] + (p1 != p2);
            }

            rank = temp;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // Step 2: Build inverse suffix array
        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }

        // Step 3: Kasai's Algorithm - LCP Array
        vector<int> lcp(n, 0);

        int h = 0;

        for (int i = 0; i < n; i++) {

            int r = pos[i];

            if (r == 0) {
                h = 0;
                continue;
            }

            int j = sa[r - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[r] = h;

            if (h > 0)
                h--;
        }

        // Step 4: Maximum LCP for every suffix
        vector<int> mx(n, 0);

        for (int i = 1; i < n; i++) {

            int a = sa[i];
            int b = sa[i - 1];

            mx[a] = max(mx[a], lcp[i]);
            mx[b] = max(mx[b], lcp[i]);
        }

        // Step 5: Find minimum unique subarray length
        int ans = n;

        for (int i = 0; i < n; i++) {

            int remaining = n - i;

            if (mx[i] < remaining) {
                ans = min(ans, mx[i] + 1);
            }
        }

        return ans;
    }
};
