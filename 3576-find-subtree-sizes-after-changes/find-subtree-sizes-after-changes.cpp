class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        vector<vector<int>> tree(n);

       
        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);
        vector<int> last(26, -1);

        
        struct Event {
            int u;
            bool exit;
            int previous;
        };

        stack<Event> st;
        st.push({0, false, -1});

       
        while (!st.empty()) {

            Event curr = st.top();
            st.pop();

            int u = curr.u;
            int c = s[u] - 'a';

            if (curr.exit) {
                last[c] = curr.previous;
                continue;
            }

            int prev = last[c];

            
            if (prev != -1)
                newParent[u] = prev;
            else
                newParent[u] = parent[u];

          
            last[c] = u;

           
            st.push({u, true, prev});

            
            for (int i = tree[u].size() - 1; i >= 0; i--) {
                st.push({tree[u][i], false, -1});
            }
        }

        
        vector<vector<int>> newTree(n);

        for (int i = 1; i < n; i++) {
            newTree[newParent[i]].push_back(i);
        }

       
        vector<int> order;
        stack<int> nodes;

        nodes.push(0);

        while (!nodes.empty()) {

            int u = nodes.top();
            nodes.pop();

            order.push_back(u);

            for (int v : newTree[u]) {
                nodes.push(v);
            }
        }

        vector<int> ans(n, 1);
        for (int i = order.size() - 1; i > 0; i--) {

            int u = order[i];

            ans[newParent[u]] += ans[u];
        }

        return ans;
    }
};