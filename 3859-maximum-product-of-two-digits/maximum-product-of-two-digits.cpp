class Solution {
public:
    int maxProduct(int n) {
       vector<int> arr;
       while (n > 0) {
        arr.push_back(n % 10); 
         n /= 10;               
       }
    sort(arr.rbegin(),arr.rend());
    int ans=arr[0]*arr[1];




   return ans;
    }
};