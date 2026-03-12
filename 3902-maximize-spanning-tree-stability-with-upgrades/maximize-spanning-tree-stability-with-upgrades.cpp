class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;

        if(rankv[a]<rankv[b]) swap(a,b);
        parent[b]=a;
        if(rankv[a]==rankv[b]) rankv[a]++;

        return true;
    }
};

class Solution {
public:
    bool can(int n, vector<vector<int>>& edges, int k, int x){

        DSU dsu(n);
        int upgrades=0;
        int used=0;

        for(auto &e:edges){
            int u=e[0], v=e[1], s=e[2], must=e[3];

            if(must){
                if(s<x) return false;
                if(dsu.unite(u,v)) used++;
                else return false;
            }
        }

        vector<pair<int,vector<int>>> opt;

        for(auto &e:edges){
            if(e[3]==0)
                opt.push_back({e[2],e});
        }

        sort(opt.begin(),opt.end(),[](auto &a,auto &b){
            return a.first>b.first;
        });

        for(auto &p:opt){
            auto e=p.second;
            int u=e[0], v=e[1], s=e[2];

            if(dsu.find(u)==dsu.find(v)) continue;

            if(s>=x){
                dsu.unite(u,v);
                used++;
            }
            else if(2*s>=x && upgrades<k){
                upgrades++;
                dsu.unite(u,v);
                used++;
            }

            if(used==n-1) break;
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int lo=1, hi=2e5;
        int ans=-1;

        while(lo<=hi){
            int mid=(lo+hi)/2;

            if(can(n,edges,k,mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }

        return ans;
    }
};