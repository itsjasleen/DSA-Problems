class Solution {
public:

    void solve(int n, int open, int close,
               string curr, vector<string>& ans) {

        // Base case
        if(curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Choice 1: Add opening bracket
        if(open < n) {
            solve(n, open + 1, close, curr + "(", ans);
        }

        // Choice 2: Add closing bracket
        if(close < open) {
            solve(n, open, close + 1, curr + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        solve(n, 0, 0, "", ans);

        return ans;
    }
};