class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;

        for (int num = left; num <= right; ++num) {
            int bits = __builtin_popcount(num);   
            
            if (isPrime(bits))
                ans++;
        }
        return ans;
    }

    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
};