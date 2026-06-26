class Fenwick {
public:
    int n;
    vector<int> bit;

    Fenwick(int sz) {
        n = sz;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> all = pref;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        Fenwick fw(all.size());

        long long ans = 0;

        for (int x : pref) {
            int id = lower_bound(all.begin(), all.end(), x) - all.begin() + 1;

            ans += fw.query(id - 1);

            fw.update(id, 1);
        }

        return ans;
    }
};