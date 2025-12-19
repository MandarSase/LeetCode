class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int a = 1;
        int zeroCount = 0;
        vector<int> ans;
        int n = nums.size();

        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroCount++;
            } else {
                a *= nums[i];
            }
        }

        
        for (int i = 0; i < n; i++) {
            if (zeroCount > 1) {
                ans.push_back(0);
            }
            else if (zeroCount == 1) {
                if (nums[i] == 0)
                    ans.push_back(a);
                else
                    ans.push_back(0);
            }
            else { 
                ans.push_back(a / nums[i]);
            }
        }

        return ans;
    }
};
