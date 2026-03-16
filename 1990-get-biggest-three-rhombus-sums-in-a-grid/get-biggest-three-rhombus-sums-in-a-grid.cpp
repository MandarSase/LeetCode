class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        set<int> s;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                for (int sz = 0; i - sz >= 0 && i + sz < m && j + 2 * sz < n; ++sz) {
                    int sum = sz ? rhombus(g, i, j, sz) : g[i][j];
                    s.insert(sum);
                    if (s.size() > 3) s.erase(s.begin());
                }

        return {s.rbegin(), s.rend()};
    }

private:
    int rhombus(const vector<vector<int>>& g, int x, int y, int sz) {
        int sum = 0;

        for (int k = 0; k < sz; ++k) sum += g[--x][++y];
        for (int k = 0; k < sz; ++k) sum += g[++x][++y];
        for (int k = 0; k < sz; ++k) sum += g[++x][--y];
        for (int k = 0; k < sz; ++k) sum += g[--x][--y];

        return sum;
    }
};