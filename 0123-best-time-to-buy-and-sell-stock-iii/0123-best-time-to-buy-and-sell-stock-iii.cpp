class Solution {
public:
int solve(int day,int buying,int tl,vector<vector<vector<int>>>&dp,vector<int>&prices){
    if(day==prices.size()||tl==0){
        return 0;
    }
    if(dp[day][buying][tl]!=-1){
        return dp[day][buying][tl];
    }
    if(buying==0){
        int buy=-prices[day]+solve(day+1,1,tl,dp,prices);
        int notbuy=solve(day+1,0,tl,dp,prices);
        return dp[day][0][tl]=max(notbuy,buy);
    }
     else{
        int notsell=solve(day+1,1,tl,dp,prices);
        int sell=prices[day]+solve(day+1,0,tl-1,dp,prices);
        return dp[day][1][tl]=max(sell,notsell);
    }
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
      vector<vector<vector<int>>> dp(
    n, vector<vector<int>>(2, vector<int>(3, -1))
);
        return solve(0,0,2,dp,prices);
    }

};