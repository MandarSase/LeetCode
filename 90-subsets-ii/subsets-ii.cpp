class Solution {
public:
    void ps(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>> &allsubsets){
     if(i==nums.size()){
        allsubsets.push_back(ans);
        return;
     }
     ans.push_back(nums[i]);
     ps(nums,ans,i+1,allsubsets);

     ans.pop_back();

     int idx=i+1;
     while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;

     ps(nums,ans,idx,allsubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allsubsets;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        ps(nums,ans,0,allsubsets);
        
        return allsubsets;
    }
};