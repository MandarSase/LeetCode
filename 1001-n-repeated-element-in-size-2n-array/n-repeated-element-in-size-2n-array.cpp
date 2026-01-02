class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n =nums.size();
        int m=n/2;
        int ans;
        unordered_map<int, int> freq;
         for (int x : nums) {
          freq[x]++;
           if (freq[x] ==m)
            ans= x;
         }
        return ans;
    }
};