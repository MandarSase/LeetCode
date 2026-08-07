class Solution {
    using um = unordered_map<int,int>;
    const um F[10] = {
        {},{},{{2,1}},{{3,1}},{{2,2}},{{5,1}},
        {{2,1},{3,1}},{{7,1}},{{2,3}},{{3,2}}
    };

public:
    string smallestNumber(string s, long long t) {
        auto [need, ok] = pc(t);
        if (!ok) return "-1";

        auto f = gc(need);
        if (sum(f) > s.size()) return build(f);

        auto pre = pc(s);
        int z = s.find('0');
        if (z == string::npos) {
            z = s.size();
            if (sub(need, pre)) return s;
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            pre = minus(pre, F[s[i] - '0']);
            if (i > z) continue;
            int rem = s.size() - i - 1;

            for (int d = s[i] - '0' + 1; d < 10; d++) {
                auto x = gc(minus(minus(need, pre), F[d]));
                if (sum(x) <= rem)
                    return s.substr(0, i) + char('0' + d) +
                           string(rem - sum(x), '1') + build(x);
            }
        }

        f = gc(need);
        return string(s.size() + 1 - sum(f), '1') + build(f);
    }

    pair<um,bool> pc(long long x) {
        um c{{2,0},{3,0},{5,0},{7,0}};
        for (int p : {2,3,5,7})
            while (x % p == 0) x /= p, c[p]++;
        return {c, x == 1};
    }

    um pc(string s) {
        um c{{2,0},{3,0},{5,0},{7,0}};
        for (char d : s)
            for (auto [p,v] : F[d - '0']) c[p] += v;
        return c;
    }

    um gc(um c) {
        int a = c[2]/3, b = c[2]%3;
        int d = c[3]/2, e = c[3]%2;
        int f = b/2, g = b%2, h = 0;
        if (g && e) g = e = 0, h = 1;
        if (e && f) g = h = 1, e = f = 0;
        return {{2,g},{3,e},{4,f},{5,c[5]},{6,h},{7,c[7]},{8,a},{9,d}};
    }

    string build(um x) {
        string r;
        for (int i = 2; i < 10; i++) r += string(x[i], '0' + i);
        return r;
    }

    bool sub(um a, um b) {
        for (auto [k,v] : a)
            if (b[k] < v) return 0;
        return 1;
    }

    um minus(um a, um b) {
        for (auto [k,v] : b) a[k] = max(0, a[k] - v);
        return a;
    }

    int sum(um a) {
        int s = 0;
        for (auto [_,v] : a) s += v;
        return s;
    }
};