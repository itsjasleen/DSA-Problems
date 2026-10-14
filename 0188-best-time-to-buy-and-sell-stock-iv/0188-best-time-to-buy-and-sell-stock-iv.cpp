class Solution {
public:
int solve(int day,int buying,int tl,vector<int>&prices,vector<vector<vector<int>>>&dp){
    if(day==prices.size()||tl==0)
    return 0;
    if(dp[day][buying][tl]!=-1)
    return dp[day][buying][tl];
    if(buying==0){
        int buy=-prices[day]+solve(day+1,1,tl,prices,dp);
        int dontbuy=solve(day+1,0,tl,prices,dp);
        return dp[day][buying][tl]=max(buy,dontbuy);
    }
    else{
        int dontsell=solve(day+1,1,tl,prices,dp);
        int sell=prices[day]+solve(day+1,0,tl-1,prices,dp);
        return dp[day][buying][tl]=max(sell,dontsell);
    }
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,0,k,prices,dp);
    }
};