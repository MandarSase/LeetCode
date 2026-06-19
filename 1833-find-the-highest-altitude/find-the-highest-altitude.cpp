class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ans = 0;
        int sum = gain[0];

        if(sum > ans)
            ans = sum;

        int i = 1;
        while(i < n) {
            sum += gain[i];
            if(sum > ans) {
                ans = sum;   
            }
            i++;
        }

        return ans;
    }
};