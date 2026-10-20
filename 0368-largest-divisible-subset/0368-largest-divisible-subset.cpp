class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<int>dp(n,1);
        vector<int>prev(n);
        for(int i=0;i<n;i++){
            prev[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
        }
        int lastindx=0;
        for(int i=0;i<n;i++){
            if(dp[i]>dp[lastindx]){
                lastindx=i;
            }
        }
        vector<int>ans;
        while(prev[lastindx]!=lastindx){
            ans.push_back(nums[lastindx]);
            lastindx=prev[lastindx];
        }
        ans.push_back(nums[lastindx]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};