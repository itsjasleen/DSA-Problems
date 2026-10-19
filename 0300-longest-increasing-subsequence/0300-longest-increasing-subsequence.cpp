
class Solution {
public:
    int solve(int index, int prevIndex, vector<int>& nums,vector<vector<int>>&dp) {
        if (index == nums.size()) {
            return 0;
        }
        if(dp[index][prevIndex+1]!=-1){
            return dp[index][prevIndex+1];
        }
        int nottake = solve(index + 1, prevIndex, nums,dp);

        int take = 0;

        if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
            take = 1 + solve(index + 1, index, nums,dp);
        }

        return dp[index][prevIndex+1]=max(take, nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums,dp);
    }
};
