class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 1e9;

        
        vector<vector<vector<int>>> f(
            k + 1, vector<vector<int>>(m, vector<int>(n, INF))
        );

        f[0][0][0] = 0;

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0)
                    f[0][i][j] = min(f[0][i][j], f[0][i - 1][j] + grid[i][j]);
                if (j > 0)
                    f[0][i][j] = min(f[0][i][j], f[0][i][j - 1] + grid[i][j]);
            }
        }

        
        unordered_map<int, vector<pair<int,int>>> g;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                g[grid[i][j]].push_back({i, j});
            }
        }

        
        vector<int> keys;
        for (auto &p : g) keys.push_back(p.first);
        sort(keys.rbegin(), keys.rend());

    
        for (int t = 1; t <= k; t++) {
            int mn = INF;

            
            for (int key : keys) {
                for (auto &[i, j] : g[key]) {
                    mn = min(mn, f[t - 1][i][j]);
                }
                for (auto &[i, j] : g[key]) {
                    f[t][i][j] = mn;
                }
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i > 0)
                        f[t][i][j] = min(f[t][i][j], f[t][i - 1][j] + grid[i][j]);
                    if (j > 0)
                        f[t][i][j] = min(f[t][i][j], f[t][i][j - 1] + grid[i][j]);
                }
            }
        }

        int ans = INF;
        for (int t = 0; t <= k; t++) {
            ans = min(ans, f[t][m - 1][n - 1]);
        }
        return ans;
    }
};
