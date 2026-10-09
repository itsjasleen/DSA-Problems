class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      int n = triangle.size();
      vector<vector<int>>dp(n);
      for(int i=0;i<n;i++){
        dp[i]=vector<int>(i+1,0);
      }
      dp[0][0]=triangle[0][0];
      for(int i=1;i<n;i++){
        for (int j=0;j<=i;j++){
        if (j==0){
            dp[i][j]=triangle[i][j]+dp[i-1][j];
        }
        else if(j==i){
            dp[i][j]=triangle[i][j]+dp[i-1][j-1];
        }
        else 
        dp[i][j]=triangle[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
        }
      }
      int answe=INT_MAX;
      for(int j=0;j<n;j++){
        answe=min(answe,dp[n-1][j]);
      }
      return answe;
    }
};