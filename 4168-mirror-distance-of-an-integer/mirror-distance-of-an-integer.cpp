class Solution {
public:
    int mirrorDistance(int n) {
        int ans;
        int a=n;
        int rev=0; 
        while(n>0){
            
            rev= rev*10 +(n%10);
            n=n/10;
        }
        cout<<rev;
        ans=abs(a-rev);
        return ans;
    }
};