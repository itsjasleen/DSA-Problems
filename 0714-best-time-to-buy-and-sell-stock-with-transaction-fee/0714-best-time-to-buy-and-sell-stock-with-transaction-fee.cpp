class Solution {
public:

    int solve(int day, int buying,
              vector<int>& prices,
              vector<vector<int>>& dp,
              int fee) {

        if(day == prices.size())
            return 0;


        if(dp[day][buying] != -1)
            return dp[day][buying];


        if(buying == 0) {

            int buy = -prices[day] +
                      solve(day+1,1,prices,dp,fee);

            int notbuy =
                      solve(day+1,0,prices,dp,fee);

            return dp[day][0] = max(buy,notbuy);

        }

        else {

            int notsell =
                    solve(day+1,1,prices,dp,fee);

            int sell = prices[day] - fee +
                       solve(day+1,0,prices,dp,fee);

            return dp[day][1] = max(sell,notsell);
        }
    }


    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        vector<vector<int>> dp(
            n,
            vector<int>(2,-1)
        );

        return solve(0,0,prices,dp,fee);
    }
};