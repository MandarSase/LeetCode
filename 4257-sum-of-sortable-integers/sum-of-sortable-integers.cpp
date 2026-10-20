
class Solution {
public:
    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;
            bool ok = true;
            int prevMax = INT_MIN;
            for (int start = 0; start < n; start += k) {
                int mn = INT_MAX;
                int mx = INT_MIN;
                int desc = 0;
                for (int i = start; i < start + k; i++) {
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                    int next = (i + 1 == start + k)
                                   ? start
                                   : i + 1;
                    if (nums[i] > nums[next])
                        desc++;
                }
                if (desc > 1 || prevMax > mn) {
                    ok = false;
                    break;
                }
                prevMax = mx;
            }
            if (ok)
                ans += k;
        }
        return ans;
    }
};
