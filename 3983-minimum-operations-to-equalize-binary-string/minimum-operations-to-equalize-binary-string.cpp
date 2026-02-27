class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();

        set<int> unused[2];
        for(int i=0;i<=n;i++)
            unused[i%2].insert(i);

        int zeros = count(s.begin(), s.end(), '0');

        queue<int> q;
        q.push(zeros);
        unused[zeros%2].erase(zeros);

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int cur = q.front(); q.pop();

                if(cur==0) return steps;

                int L = cur + k - 2*min(cur,k);
                int R = cur + k - 2*max(k-n+cur,0);

                auto &st = unused[L%2];
                auto it = st.lower_bound(L);

                while(it!=st.end() && *it<=R) {
                    q.push(*it);
                    it = st.erase(it);
                }
            }
            steps++;
        }
        return -1;
    }
};