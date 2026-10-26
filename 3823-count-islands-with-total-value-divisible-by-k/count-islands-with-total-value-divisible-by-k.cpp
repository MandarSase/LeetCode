class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0 || vis[i][j])
                    continue;

                stack<pair<int, int>> st;
                st.push({i, j});
                vis[i][j] = true;

                long long sum = 0;

                while (!st.empty()) {
                    auto [x, y] = st.top();
                    st.pop();

                    sum += grid[x][y];

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if (nx >= 0 && nx < m &&
                            ny >= 0 && ny < n &&
                            grid[nx][ny] > 0 &&
                            !vis[nx][ny]) {

                            vis[nx][ny] = true;
                            st.push({nx, ny});
                        }
                    }
                }

                if (sum % k == 0)
                    ans++;
            }
        }

        return ans;
    }
};