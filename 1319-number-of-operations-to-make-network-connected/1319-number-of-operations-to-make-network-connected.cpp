class Solution {
public:
    vector<int>parent;
    int find(int x){
        if (parent[x]==x){
            return x;
        }
         return parent[x]=find(parent[x]);
        }
    

        void unionset(int a,int b){
            int parentA=find(a);
            int parentB=find(b);

            if(parentA!=parentB){
                parent[parentB]=parentA;
            }
        }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        return -1;

        parent.resize(n);

        for (int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto connection:connections){

            int u=connection[0];
            int v=connection[1];
            unionset(u,v);

        }
        int components=0;
        //finding no od connected gp
        for(int i=0;i<n;i++){
            if(find(i)==i){
                components++;
            }
        }
        return components-1;
        
    }
};