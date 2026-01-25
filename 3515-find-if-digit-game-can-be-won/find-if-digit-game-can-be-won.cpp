class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n=nums.size();
        int s=0,d=0;

        for(int i=0;i<n;i++){
            if(nums[i]>=10){
                d+=nums[i];
            }
            else{
                s+=nums[i];

            }

        }
        if(s==d) return false;

        return true;
        
    }
};