class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n=s.size();
       string ans(n,' ');
        for(int i=0;i<n;i++){
            int j =(i+k)%n;
            ans[i]=s[j];
        }
        return ans;
    }
};