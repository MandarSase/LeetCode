class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> fromLeft(
            m, vector<long long>(n, 0)
        );

        vector<vector<long long>> fromTop(
            m, vector<long long>(n, 0)
        );

        // The robot starts at (0, 0).
        fromLeft[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // The destination is an empty cell.
                if (i == m - 1 && j == n - 1) {
                    return (fromLeft[i][j] + fromTop[i][j]) % MOD;
                }

                if (grid[i][j] == 0) {
                    // Empty cell: the robot can choose right or down.
                    long long ways =
                        (fromLeft[i][j] + fromTop[i][j]) % MOD;

                    // Move right.
                    if (j + 1 < n) {
                        fromLeft[i][j + 1] =
                            (fromLeft[i][j + 1] + ways) % MOD;
                    }

                    // Move down.
                    if (i + 1 < m) {
                        fromTop[i + 1][j] =
                            (fromTop[i + 1][j] + ways) % MOD;
                    }
                } 
                else {
                    // Mirror:
                    // Entering from the left redirects the robot down.
                    if (i + 1 < m) {
                        fromTop[i + 1][j] =
                            (fromTop[i + 1][j] + fromLeft[i][j]) % MOD;
                    }

                    // Entering from the top redirects the robot right.
                    if (j + 1 < n) {
                        fromLeft[i][j + 1] =
                            (fromLeft[i][j + 1] + fromTop[i][j]) % MOD;
                    }
                }
            }
        }

        return 0;
    }
};