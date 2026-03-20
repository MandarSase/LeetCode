class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i + k <= m; ++i) {
            for (int j = 0; j + k <= n; ++j) {

                vector<int> vals;

                
                for (int x = i; x < i + k; ++x)
                    for (int y = j; y < j + k; ++y)
                        vals.push_back(grid[x][y]);

                
                sort(vals.begin(), vals.end());
                vals.erase(unique(vals.begin(), vals.end()), vals.end());

                
                int mn = INT_MAX;
                for (int t = 1; t < vals.size(); ++t)
                    mn = min(mn, vals[t] - vals[t - 1]);

                
                ans[i][j] = (vals.size() <= 1) ? 0 : mn;
            }
        }

        return ans;
    }
};