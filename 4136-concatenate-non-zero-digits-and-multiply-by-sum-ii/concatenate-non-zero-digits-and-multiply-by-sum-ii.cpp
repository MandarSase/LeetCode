class Solution {
public:
    static constexpr int MOD = 1000000007;

    struct BIT {
        int n;
        vector<long long> bit;

        BIT(int n): n(n), bit(n + 1, 0) {}

        void add(int idx, long long val) {
            idx++;
            while (idx <= n) {
                bit[idx] = (bit[idx] + val) % MOD;
                idx += idx & -idx;
            }
        }

        long long query(int idx) {
            long long res = 0;
            idx++;
            while (idx > 0) {
                res = (res + bit[idx]) % MOD;
                idx -= idx & -idx;
            }
            return res;
        }

        long long query(int l, int r) {
            if (l > r) return 0;
            return (query(r) - query(l - 1) + MOD) % MOD;
        }
    };

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<long long> pw(n + 1), inv(n + 1);

        auto modpow = [&](long long a, long long e) {
            long long res = 1;
            while (e) {
                if (e & 1) res = res * a % MOD;
                a = a * a % MOD;
                e >>= 1;
            }
            return res;
        };

        pw[0] = 1;
        for (int i = 1; i <= n; i++)
            pw[i] = pw[i - 1] * 10 % MOD;

        inv[n] = modpow(pw[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--)
            inv[i] = inv[i + 1] * 10 % MOD;

        BIT cnt(n), sum(n), val(n);

        int totalNZ = 0;

        for (char c : s)
            if (c != '0')
                totalNZ++;

        int seen = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') continue;

            int d = s[i] - '0';

            cnt.add(i, 1);
            sum.add(i, d);

            int exp = totalNZ - seen - 1;
            val.add(i, d * pw[exp] % MOD);

            seen++;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0], r = q[1];

            long long digitSum = sum.query(l, r);

            if (digitSum == 0) {
                ans.push_back(0);
                continue;
            }

            long long before = cnt.query(0, l - 1);
            long long inside = cnt.query(l, r);

            long long X = val.query(l, r);
            X = X * inv[totalNZ - before - inside] % MOD;

            ans.push_back(X * digitSum % MOD);
        }

        return ans;
    }
};