class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;

        vector<int> up(m + 1), down(m + 1);
        vector<int> newUp(m + 1), newDown(m + 1);
        vector<int> pref(m + 1), suff(m + 2);

        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        for (int len = 3; len <= n; len++) {

            pref[0] = 0;
            for (int v = 1; v <= m; v++) {
                pref[v] = (pref[v - 1] + down[v]) % MOD;
            }

            suff[m + 1] = 0;
            for (int v = m; v >= 1; v--) {
                suff[v] = (suff[v + 1] + up[v]) % MOD;
            }

            for (int v = 1; v <= m; v++) {
                newUp[v] = pref[v - 1];
                newDown[v] = suff[v + 1];
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;
        for (int v = 1; v <= m; v++) {
            ans += up[v];
            ans += down[v];
        }

        return ans % MOD;
    }
};