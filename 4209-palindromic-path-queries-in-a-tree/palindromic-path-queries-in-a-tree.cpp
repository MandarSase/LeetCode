class Solution {
public:
    static constexpr int LOG = 17;

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n), tout(n), depth(n);
        vector<int> rootMask(n);
        vector<array<int, LOG>> up(n);

        int timer = 0;

        stack<tuple<int, int, bool>> st;
        st.push({0, 0, false});

        while (!st.empty()) {
            auto [u, p, exiting] = st.top();
            st.pop();

            if (exiting) {
                tout[u] = timer;
                continue;
            }

            tin[u] = timer++;

            up[u][0] = p;

            for (int j = 1; j < LOG; j++) {
                up[u][j] = up[up[u][j - 1]][j - 1];
            }

            rootMask[u] =
                (u == 0 ? 0 : rootMask[p]) ^
                (1 << (s[u] - 'a'));

            st.push({u, p, true});

            for (int v : adj[u]) {
                if (v == p) continue;

                depth[v] = depth[u] + 1;
                st.push({v, u, false});
            }
        }

        vector<int> bit(n + 1, 0);

        auto add = [&](int idx, int val) {
            for (idx++; idx <= n; idx += idx & -idx) {
                bit[idx] ^= val;
            }
        };

        auto prefixXor = [&](int idx) {
            int res = 0;

            for (idx++; idx > 0; idx -= idx & -idx) {
                res ^= bit[idx];
            }

            return res;
        };

        auto rangeXor = [&](int l, int r, int val) {
            add(l, val);

            if (r < n) {
                add(r, val);
            }
        };

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) {
                swap(u, v);
            }

            int diff = depth[u] - depth[v];
            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j)) {
                    u = up[u][j];
                }
            }
            if (u == v) return u;
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[u][j] != up[v][j]) {
                    u = up[u][j];
                    v = up[v][j];
                }
            }

            return up[u][0];
        };
        auto getRootMask = [&](int u) {
            return rootMask[u] ^ prefixXor(tin[u]);
        };
        vector<bool> answer;
        for (string& q : queries) {
            string type;
            int u;
            stringstream ss(q);
            ss >> type >> u;
            if (type == "update") {
                char c;
                ss >> c;
                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int delta = oldMask ^ newMask;
                if (delta != 0) {
                    rangeXor(tin[u], tout[u], delta);
                    s[u] = c;
                }
            } else {
                int v;
                ss >> v;
                int w = lca(u, v);
                int mask =
                    getRootMask(u) ^
                    getRootMask(v) ^
                    (1 << (s[w] - 'a'));
                answer.push_back(
                    mask == 0 || (mask & (mask - 1)) == 0
                );
            }
        }

        return answer;
    }
};