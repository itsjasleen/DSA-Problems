
class Solution {
public:
    int solve(int index, int target, vector<int>& nums,
              vector<vector<int>>& dp) {
        if (index == 0) {
            if (target == 0 && nums[0] == 0) return 2;
            if (target == 0 || nums[0] == target) return 1;
            return 0;
        }
        if (dp[index][target] != -1)
            return dp[index][target];
        int notTake = solve(index - 1, target, nums, dp);
        int take = 0;
        if (nums[index] <= target) {
            take = solve(index - 1, target - nums[index],
                         nums, dp);
        }
        return dp[index][target] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums) total += x;
        if (abs(target) > total || (total + target) % 2 != 0)
            return 0;
        int newTarget = (total + target) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(newTarget + 1, -1));
        return solve(n - 1, newTarget, nums, dp);
    }
};
