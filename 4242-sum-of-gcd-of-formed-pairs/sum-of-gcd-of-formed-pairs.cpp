class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefix;

        int mx = 0;

        for(int x : nums)
        {
            mx = max(mx, x);
            prefix.push_back(gcd(x, mx));
        }

        sort(prefix.begin(), prefix.end());

        long long ans = 0;

        int l = 0;
        int r = n - 1;

        while(l < r)
        {
            ans += gcd(prefix[l], prefix[r]);
            l++;
            r--;
        }

        return ans;
    }
};