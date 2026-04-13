class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minimum=INT_MAX;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==target){
                int a=abs(i-start);
                minimum=min(minimum,a);

            }

        }
        return minimum;
    }
};