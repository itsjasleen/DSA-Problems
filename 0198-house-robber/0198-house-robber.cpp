class Solution {
public:
    int rob(vector<int>& nums) {
       vector<int>dp(nums.size());
       dp[0]=nums[0];
       if(nums.size()>=2)
       dp[1]=max(nums[0],nums[1]);
       for(int i=2;i<nums.size();i++){
        int take=nums[i]+dp[i-2];
        int dontakee=dp[i-1];
        dp[i]=max(take,dontakee);
       }
       return dp[nums.size()-1];
    }
};