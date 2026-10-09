
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(
                n, vector<int>(n, -1)
            )
        );

        // Starting positions
        dp[0][0][n-1] = grid[0][0];

        if(n > 1)
            dp[0][0][n-1] += grid[0][n-1];

        // Move row by row
        for(int i = 0; i < m-1; i++) {
            for(int j1 = 0; j1 < n; j1++) {
                for(int j2 = 0; j2 < n; j2++) {

                    if(dp[i][j1][j2] == -1)
                        continue;

                    for(int d1 = -1; d1 <= 1; d1++) {
                        for(int d2 = -1; d2 <= 1; d2++) {

                            int nj1 = j1 + d1;
                            int nj2 = j2 + d2;

                            if(nj1 >= 0 && nj1 < n &&
                               nj2 >= 0 && nj2 < n) {

                                int cherries = grid[i+1][nj1];

                                if(nj1 != nj2)
                                    cherries += grid[i+1][nj2];

                                int total = dp[i][j1][j2] + cherries;

                                if(dp[i+1][nj1][nj2] == -1)
                                    dp[i+1][nj1][nj2] = total;
                                else
                                    dp[i+1][nj1][nj2] =
                                        max(dp[i+1][nj1][nj2], total);
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;

        for(int j1 = 0; j1 < n; j1++) {
            for(int j2 = 0; j2 < n; j2++) {
                ans = max(ans, dp[m-1][j1][j2]);
            }
        }

        return ans;
    }
};
