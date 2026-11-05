class Solution {
public:
int solve(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
    if(i+1==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int mini=INT_MAX;

    for(int k=i+1;k<j;k++){
        int cost=cuts[j]-cuts[i]+solve(i,k,cuts,dp)+solve(k,j,cuts,dp);

        mini=min(cost ,mini);
    }
    return dp[i][j]=mini;
}
    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0);
        cuts.push_back(n);
        int s=cuts.size();
        vector<vector<int>>dp(s,vector<int>(s,-1));
        
        sort(cuts.begin(),cuts.end());
        return solve(0,s-1,cuts,dp);
    }
};