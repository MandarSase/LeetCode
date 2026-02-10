class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> freq;
            int even = 0, odd = 0;

            for (int j = i; j < n; ++j) {
                if (++freq[nums[j]] == 1) { 
                    if (nums[j] & 1) odd++;
                    else even++;
                }
                if (even == odd) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
