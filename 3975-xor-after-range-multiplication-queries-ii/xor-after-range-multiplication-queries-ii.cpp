class Solution {
public:
    
    long long binpow(long long a,long long e,int md){
        long long res = 1;
        while(e>0){
            if(e&1){
                res = (res*a)%md;
            }
            a = (a*a)%md;
            e>>=1;
        }
        return res;
    }
    long long mdinv(long long n, int md){
        return binpow(n,md-2,md);
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), md = 1e9 + 7;
        int limit = sqrt(n); 
        
        unordered_map<int, vector<vector<int>>> mp;
        for(int i=0;i<queries.size();i++){
            int l = queries[i][0], r = queries[i][1], k = queries[i][2], v = queries[i][3];
            if(k>=limit){
                for(int j=l;j<=r;j+=k){
                    nums[j] = ((long long)nums[j]*v)%md;
                }
            }else{
                mp[k].push_back(queries[i]);
            }
        }

        for(auto &[k,query] : mp){
            vector<long long> diff(n,1);
            for(auto &q : query){
                int l = q[0], r = q[1], v = q[3];
                diff[l] = (diff[l]*v)%md;
                int steps = (r-l)/k;
                int next = l + (steps + 1)*k;
                if(next < n){
                    diff[next] = (diff[next] * mdinv(v,md))%md;
                }
            }
            
            for(int i=0;i<n;i++){
                if(i>=k) diff[i] = (diff[i] * diff[i-k])%md;
                nums[i] = ((long long)nums[i]*diff[i])%md;
            }
        }

        int ans = 0;
        for(auto x : nums) ans = ans^x;
        return ans;  
    }
};