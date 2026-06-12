class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    vector<vector<int>> up;
    vector<int> depth;
    int LOG;

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    void dfs(int u, int p, vector<vector<int>>& g) {
        up[0][u] = p;

        for (int i = 1; i < LOG; i++) {
            up[i][u] = up[i - 1][u] == -1
                ? -1
                : up[i - 1][up[i - 1][u]];
        }

        for (int v : g[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u, g);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int i = LOG - 1; i >= 0; i--) {
            if ((diff >> i) & 1)
                u = up[i][u];
        }

        if (u == v)
            return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[i][u] != up[i][v]) {
                u = up[i][u];
                v = up[i][v];
            }
        }

        return up[0][u];
    }

    vector<int> assignEdgeWeights(
        vector<vector<int>>& edges,
        vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        vector<vector<int>> g(n + 1);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        LOG = 18;
        while ((1 << LOG) <= n)
            LOG++;

        up.assign(LOG, vector<int>(n + 1, -1));
        depth.assign(n + 1, 0);

        dfs(1, -1, g);

        vector<int> ans;

        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];

            int w = lca(u, v);

            long long d =
                1LL * depth[u] +
                depth[v] -
                2LL * depth[w];

            if (d == 0)
                ans.push_back(0);
            else
                ans.push_back((int)modPow(2, d - 1));
        }

        return ans;
    }
};