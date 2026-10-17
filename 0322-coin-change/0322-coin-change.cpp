class Solution {
public:
int solve(int index,int amt,vector<int>&coins,vector<vector<int>>&dp){
    if(index==0){
        if(amt%coins[0]==0){
            return amt/coins[0];
        }
        else return 1e9;
    }
    if (dp[index][amt]!=-1){
        return dp[index][amt];
    }

    int nottake=solve(index-1,amt,coins,dp);

    int take=INT_MAX;
    if(coins[index]<=amt){
        take=1+solve(index,amt-coins[index],coins,dp);

    }
    return dp[index][amt]=min(take,nottake);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,amount,coins,dp);
        if(ans<1e9){
            return ans;
        }
        else return -1;
    }
};