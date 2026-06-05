class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;

    struct State {
        bool vis = false;
        Node val;
    };

    State dp[20][2][2][17][11][11];

    Node dfs(int pos, int tight, int started,
             int len, int prev2, int prev1) {

        if (pos == (int)s.size()) {
            return {1, 0};
        }

        auto &memo = dp[pos][tight][started][len][prev2 + 1][prev1 + 1];

        if (!tight && memo.vis)
            return memo.val;

        int limit = tight ? s[pos] - '0' : 9;

        Node ans = {0, 0};

        for (int d = 0; d <= limit; d++) {

            int ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt =
                    dfs(pos + 1, ntight, 0, 0, -1, -1);

                ans.cnt += nxt.cnt;
                ans.wav += nxt.wav;
            } else {

                int add = 0;

                if (len >= 2) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        add = 1;
                }

                int nprev2 = (len == 0 ? -1 : prev1);
                int nprev1 = d;

                Node nxt =
                    dfs(pos + 1, ntight, 1,
                        len + 1, nprev2, nprev1);

                ans.cnt += nxt.cnt;
                ans.wav += nxt.wav + nxt.cnt * add;
            }
        }

        if (!tight) {
            memo.vis = true;
            memo.val = ans;
        }

        return ans;
    }

    long long solve(long long x) {
        if (x <= 0) return 0;

        s = to_string(x);
        memset(dp, 0, sizeof(dp));

        return dfs(0, 1, 0, 0, -1, -1).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};