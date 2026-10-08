class Solution {
public:
int solve(vector<int>&nums,int start,int end){
    int size=end-start+1;
    vector<int>dp(size);
    dp[0]=nums[start];
    if(size>=2){
        dp[1]=max(nums[start],nums[start+1]);
    }
    for(int i=2;i<size;i++){
        int take=nums[start+i]+dp[i-2];
        int dontake=dp[i-1];
        dp[i]=max(take,dontake);
    }
    return dp[size-1];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int case1=solve(nums,0,n-2);
        int case2=solve(nums,1,n-1);
        int ok=max(case1,case2);
        return ok;
    }

};