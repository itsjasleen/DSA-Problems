class Solution {
public:
    int solve(int index, int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(index==0){
            if(amount%coins[index]==0)
              return 1;
            return 0;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int nottake=solve(index-1,amount,coins,dp);
        int take=0;
        if(coins[index]<=amount){
            take=solve(index,amount-coins[index],coins,dp);
        }
        return dp[index][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return solve(n-1,amount,coins,dp);
    }
};