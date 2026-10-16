class Solution {
public:
    int solve(int day, int buying, vector<int>& prices,
              vector<vector<int>>& dp) {

        if (day >= prices.size())
            return 0;
        if (dp[day][buying] != -1)
            return dp[day][buying];

        if (buying == 0) {

            int buy = -prices[day] +
                      solve(day + 1, 1, prices, dp);
            int notbuy =
                      solve(day + 1, 0, prices, dp);

            return dp[day][0] = max(buy, notbuy);
        }
        else {
            int notsell =
                      solve(day + 1, 1, prices, dp);

            int sell = prices[day] +
                       solve(day + 2, 0, prices, dp);

            return dp[day][1] = max(sell, notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(0, 0, prices, dp);
    }
};