class Solution {
public:
    int minMoves(vector<string>& g, int E) {
        int m=g.size(), n=g[0].size(), k=0, sr, sc;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++) {
                if(g[i][j]=='S') sr=i,sc=j;
                if(g[i][j]=='L') g[i][j]='0'+k++;
            }

        int N=1<<k, full=N-1;
        vector<vector<vector<int>>> best(m,
            vector<vector<int>>(n,vector<int>(N,-1)));

        queue<array<int,4>> q;
        q.push({sr,sc,0,E});
        best[sr][sc][0]=E;

        int d[5]={1,0,-1,0,1};

        for(int steps=0;!q.empty();steps++) {
            int z=q.size();

            while(z--) {
                auto [r,c,mask,e]=q.front(); q.pop();

                if(mask==full) return steps;

                for(int x=0;x<4;x++) {
                    int a=r+d[x], b=c+d[x+1];
                    if(a<0||a>=m||b<0||b>=n||g[a][b]=='X'||e==0)
                        continue;

                    int ne=e-1, nm=mask;

                    if(g[a][b]=='R') ne=E;
                    if(g[a][b]>='0'&&g[a][b]<='9')
                        nm|=1<<(g[a][b]-'0');

                    if(ne>best[a][b][nm]) {
                        best[a][b][nm]=ne;
                        q.push({a,b,nm,ne});
                    }
                }
            }
        }

        return -1;
    }
};