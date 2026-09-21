class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int a : nums) {

            vector<long long> ndp(k, 0);

            ndp[a % k]++;

            for (int r = 0; r < k; r++) {

                int newRem = (r * 1LL * a) % k;

                ndp[newRem] += dp[r];
            }

            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }

            dp = ndp;
        }

        return ans;
    }
};