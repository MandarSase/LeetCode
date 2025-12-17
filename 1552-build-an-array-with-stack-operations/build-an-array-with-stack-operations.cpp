class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 0; 

        for(int x = 1; x <= n && i < target.size(); x++) {
            ans.push_back("Push");

            if(x == target[i]) {
                i++;  
            } else {
                ans.push_back("Pop"); 
            }
        }

        return ans;
    }
};
