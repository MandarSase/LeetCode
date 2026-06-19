class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int ans=0;
        int sum=gain[0];
        int i=1;
        if(sum>ans){
                ans=sum;
                }
        while(i<n){
            sum=sum+gain[i];
            if(sum>ans){
                ans=sum;
            }
            i++;
        }
        
        return ans;
    }
};