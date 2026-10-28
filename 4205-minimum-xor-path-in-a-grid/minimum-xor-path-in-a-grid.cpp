class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<bitset<1024>> prev(n), curr(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bitset<1024> reachable;

                if (i == 0 && j == 0) {
                    reachable.set(0);
                } else {
                    if (i > 0)
                        reachable |= prev[j];

                    if (j > 0)
                        reachable |= curr[j - 1];
                }

                bitset<1024> next;
                int val = grid[i][j];

                for (int x = 0; x < 1024; x++) {
                    if (reachable[x])
                        next.set(x ^ val);
                }

                curr[j] = next;
            }

            prev = curr;
            for (int j = 0; j < n; j++)
                curr[j].reset();
        }

        for (int x = 0; x < 1024; x++) {
            if (prev[n - 1][x])
                return x;
        }

        return -1;
    }
};