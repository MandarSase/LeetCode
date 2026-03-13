class Solution {
public:

    bool can(long long T, int H, vector<int>& w){
        long long total = 0;

        for(long long t : w){
            long long val = (2*T)/t;

            long long x = (sqrt(1 + 4*val) - 1) / 2;

            total += x;
            if(total >= H) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long lo = 0;
        long long hi = 1e18;
        long long ans = hi;

        while(lo <= hi){
            long long mid = (lo + hi) / 2;

            if(can(mid, mountainHeight, workerTimes)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};