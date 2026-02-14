class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        vector<double> dp(query_row + 1, 0.0);
        dp[0] = poured;
        
        for (int i = 0; i < query_row; i++) {
            for (int j = i; j >= 0; j--) {
                double overflow = max(0.0, (dp[j] - 1.0) / 2.0);
                
                dp[j] = overflow;
                dp[j + 1] += overflow;
            }
        }
        
        return min(1.0, dp[query_glass]);
    }
};
