class Solution {
public:
    int totalNumbers(vector<int>& d) {
        int cnt[10] = {}, ans = 0;
        for (int x : d) cnt[x]++;
        for (int x = 100; x <= 998; x += 2) {
            int a = x % 10, b = x / 10 % 10, c = x / 100;
            int need[10] = {};
            need[a]++; need[b]++; need[c]++;
            bool ok = true;
            for (int i = 0; i < 10; i++)
                if (need[i] > cnt[i]) { ok = false; break; }
            if (ok) ans++;
        }
        return ans;
    }
};