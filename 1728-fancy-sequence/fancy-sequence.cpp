class Fancy {
public:
    static const long long MOD = 1000000007;

    vector<long long> vals;
    long long a = 1;   
    long long b = 0;   

    void append(int val) {
        long long x = (val - b + MOD) % MOD;
        x = (x * modPow(a, MOD - 2)) % MOD;   
        vals.push_back(x);
    }

    void addAll(int inc) {
        b = (b + inc) % MOD;
    }

    void multAll(int m) {
        a = (a * m) % MOD;
        b = (b * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= vals.size()) return -1;
        return (a * vals[idx] + b) % MOD;
    }

private:
    long long modPow(long long x, long long n) {
        long long res = 1;
        x %= MOD;

        while (n > 0) {
            if (n & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            n >>= 1;
        }
        return res;
    }
};