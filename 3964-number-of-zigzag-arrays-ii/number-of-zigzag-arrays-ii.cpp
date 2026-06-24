class Solution {
public:
    static const int MOD = 1e9 + 7;
    using ll = long long;

    using Matrix = vector<vector<ll>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<ll> multiplyMatVec(const Matrix& A, const vector<ll>& v) {
        int n = A.size();
        vector<ll> res(n, 0);

        for (int i = 0; i < n; i++) {
            ll sum = 0;
            for (int j = 0; j < n; j++) {
                sum = (sum + A[i][j] * v[j]) % MOD;
            }
            res[i] = sum;
        }
        return res;
    }

    Matrix matPow(Matrix base, long long exp) {
        int n = base.size();
        Matrix result(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++) result[i][i] = 1;

        while (exp > 0) {
            if (exp & 1) result = multiply(result, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return result;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        // Base state for length = 2
        vector<ll> state(sz, 0);

        // up[v] stored at index (v-1)
        // down[v] stored at index m + (v-1)
        for (int v = 1; v <= m; v++) {
            state[v - 1] = v - 1;         // up[v]
            state[m + (v - 1)] = m - v;   // down[v]
        }

        if (n == 2) {
            ll ans = 0;
            for (ll x : state) ans = (ans + x) % MOD;
            return (int)ans;
        }

        // Transition matrix
        Matrix T(sz, vector<ll>(sz, 0));

        for (int v = 1; v <= m; v++) {
            // newUp[v] = sum of down[u] for u < v
            for (int u = 1; u < v; u++) {
                T[v - 1][m + (u - 1)] = 1;
            }

            // newDown[v] = sum of up[u] for u > v
            for (int u = v + 1; u <= m; u++) {
                T[m + (v - 1)][u - 1] = 1;
            }
        }

        Matrix P = matPow(T, n - 2);
        vector<ll> finalState = multiplyMatVec(P, state);

        ll ans = 0;
        for (ll x : finalState) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};