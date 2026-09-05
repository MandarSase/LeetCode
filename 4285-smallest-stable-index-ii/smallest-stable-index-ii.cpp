class Solution {
public:
    int firstStableIndex(vector<int>& a, int k) {
        int n=a.size(), mx=0;
        vector<int> mn(n);
        
        mn[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
            mn[i]=min(a[i],mn[i+1]);

        for(int i=0;i<n;i++) {
            mx=max(mx,a[i]);
            if(mx-mn[i]<=k) return i;
        }
        return -1;
    }
};