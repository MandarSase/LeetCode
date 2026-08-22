class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0,p=1;
        for(int x=n;x;x/=10)
            s+=x%10,p*=x%10;
        return n%(s+p)==0;
    }
};