class Solution {
public:

    bool isPrime(int x) {
        if (x < 2) return false;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }

        return true;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;

        // prime -> indices divisible by prime
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {

            int val = nums[i];

            // find prime factors
            for (int p = 2; p * p <= val; p++) {

                if (val % p == 0) {

                    if (isPrime(p))
                        mp[p].push_back(i);

                    while (val % p == 0)
                        val /= p;
                }
            }

            if (val > 1)
                mp[val].push_back(i);
        }

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        int jumps = 0;

        unordered_set<int> usedPrime;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                int i = q.front();
                q.pop();

                if (i == n - 1)
                    return jumps;

                // i-1
                if (i - 1 >= 0 && !vis[i - 1]) {
                    vis[i - 1] = 1;
                    q.push(i - 1);
                }

                // i+1
                if (i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = 1;
                    q.push(i + 1);
                }

                // teleportation
                if (isPrime(nums[i])) {

                    int p = nums[i];

                    if (!usedPrime.count(p)) {

                        usedPrime.insert(p);

                        for (int nxt : mp[p]) {

                            if (!vis[nxt]) {
                                vis[nxt] = 1;
                                q.push(nxt);
                            }
                        }
                    }
                }
            }

            jumps++;
        }

        return -1;
    }
};