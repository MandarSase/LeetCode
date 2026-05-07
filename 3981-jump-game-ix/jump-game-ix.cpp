class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n), suffMin(n);

        prefMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        vector<int> ans(n);

        int start = 0;
        int compMax = nums[0];

        for (int i = 0; i < n - 1; i++) {
            compMax = max(compMax, nums[i]);

            // Split components here
            if (prefMax[i] <= suffMin[i + 1]) {

                for (int j = start; j <= i; j++) {
                    ans[j] = compMax;
                }

                start = i + 1;
                compMax = nums[start];
            }
        }

        compMax = max(compMax, nums[n - 1]);

        for (int j = start; j < n; j++) {
            ans[j] = compMax;
        }

        return ans;
    }
};