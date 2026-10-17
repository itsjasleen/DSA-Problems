class Solution {
public:
int solve(int index,int target,vector<int>&stones,vector<vector<int>>&dp){

    if(index==0){
        if(stones[0]<=target)
        return stones[0];
        else
        return 0;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    int nottake=solve(index-1,target,stones,dp);
    int take=0;
    if(stones[index]<=target){
    take=stones[index]+solve(index-1,target-stones[index],stones,dp);
        }

        return dp[index][target]=max(nottake,take);
}
    int lastStoneWeightII(vector<int>& stones) {
        int total=0;
        for(int stone:stones){
            total+=stone;
        }
        int target=total/2;
        int n=stones.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));

        int bestsum=solve(n-1,target,stones,dp);
        return total-2*bestsum;
    }
};