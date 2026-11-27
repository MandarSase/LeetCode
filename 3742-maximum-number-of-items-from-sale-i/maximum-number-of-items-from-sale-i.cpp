
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        // Step 1: Calculate free-copy bonus
        vector<int> bonus(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i != j &&
                    items[j][0] % items[i][0] == 0) {
                    bonus[i]++;
                }
            }
        }

        // Step 2: DP
        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {

            int price = items[i][1];
            vector<int> next = dp;

            for (int b = price; b <= budget; b++) {

                // Additional copy of current item
                next[b] = max(next[b],
                              next[b - price] + 1);

                // First copy of current item
                next[b] = max(next[b],
                              dp[b - price] + 1 + bonus[i]);
            }

            dp = next;
        }

        return dp[budget];
    }
};
