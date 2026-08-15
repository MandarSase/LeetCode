class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        for (int n : nums) x ^= n;

        if (x) return nums.size();

        for (int n : nums)
            if (n) return nums.size() - 1;

        return 0;
    }
};