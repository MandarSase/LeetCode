class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for (int x : nums)
            totalSum += x;

        vector<int> ans(n);

        int leftSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum -= nums[i]; 

            ans[i] = abs(leftSum - totalSum);

            leftSum += nums[i];
        }

        return ans;
    }
};