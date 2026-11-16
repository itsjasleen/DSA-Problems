class Solution {
public:
    void solve(int index, vector<int>& nums,
               vector<int>& current,
               vector<vector<int>>& ans) {

        ans.push_back(current);

        for(int i = index; i < nums.size(); i++) {

            if(i > index && nums[i] == nums[i-1]) {
                continue;
            }

            current.push_back(nums[i]);

            solve(i+1, nums, current, ans);

            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> current;

        solve(0, nums, current, ans);

        return ans;
    }
};