class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        bool seen[4000000] = {false};
        vector<int>ans;

        for(int c : nums){
            
            if(seen[c] ){
                
                ans.push_back(c); 

            }
            seen[c]=true;
        }
        return ans;
    }
};