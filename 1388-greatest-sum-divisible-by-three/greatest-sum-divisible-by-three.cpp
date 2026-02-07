class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);

        for (int num : nums) {
            vector<int> prev = dp;  
            for (int r = 0; r < 3; r++) {
                int newSum = prev[r] + num;
                dp[newSum % 3] = max(dp[newSum % 3], newSum);
            }
        }
        return dp[0];
    }
};
