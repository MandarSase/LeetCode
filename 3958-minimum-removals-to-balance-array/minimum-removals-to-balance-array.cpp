class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        ranges::sort(nums);
        int n = nums.size();
        int ans = n;
        int j = 0;

        for (int i = 0; i < n; ++i) {
            while (j < n && 1LL * nums[j] <= 1LL * nums[i] * k) {
                j++;
            }
            ans = min(ans, n - (j - i));
        }
        return ans;
    }
};
