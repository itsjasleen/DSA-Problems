class Solution {
public:
    vector<int>parent,size;
    int find(int x){
        if (parent[x]==x)
        return x;
    return parent[x]=find(parent[x]);
    }
    
    void unionSet(int a,int b){
        int pa= find(a);
        int pb= find(b);

        if(pa==pb)
        return;
        if(size[pa]<size[pb])
        swap(pa,pb);
        parent[pb]=pa;
        size[pa]+=size[pb];
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        parent.resize(n*n);
        size.resize(n*n,1);

        for(int i=0;i<n*n;i++)
        parent[i]=i;
        
        vector<pair<int,int>>pos(n*n);
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                pos[grid[r][c]]={r,c};
            }
        }
        vector<int>active(n*n,0);
        int dr[]={0,-1,0,1};
        int dc[]={1,0,-1,0};
        for(int t=0;t<n*n;t++){
            int r=pos[t].first;
            int c=pos[t].second;
            int node=r*n+c;
            active[node]=1;
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0&&nr<n&&nc>=0&&nc<n){
                    int neigh=nr*n+nc;
                    if(active[neigh]){
                        unionSet(node,neigh);
                    }
                }
            }
            if(find(0)==find(n*n-1))
            return t;
        }
        return -1;
    }
};