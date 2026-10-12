class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int day=n-1;day>=0;day--){
            for(int cap=1;cap<=2;cap++){
                dp[day][0][cap]=max(dp[day+1][0][cap],dp[day+1][1][cap]-prices[day]);
                dp[day][1][cap]=max(dp[day+1][1][cap],dp[day+1][0][cap-1]+prices[day]);
            }
        }
        return dp[0][0][2];
    }
};