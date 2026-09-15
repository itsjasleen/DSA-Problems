class Solution {
public:
    vector<vector<int>>adj;
    vector<int>vis,tin;
    vector<int>low;
    vector<vector<int>>ans;
    int time=0;

    void dfs(int u, int parent){
        vis[u]=1;
        tin[u]=low[u]=time++;
        for(int v:adj[u]){
            if(v==parent){
                continue;
            }
            if(!vis[v]){
                dfs(v,u);
                low[u]=min(low[u],low[v]);

                if(low[v]>tin[u])
                ans.push_back({u,v});

            }
            else{
                low[u]=min(low[u],tin[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        vis.resize(n,0);
        tin.resize(n,0);
        low.resize(n,0);
        for(auto e:connections){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }



        dfs(0,-1);
        return ans;
    }
    
};