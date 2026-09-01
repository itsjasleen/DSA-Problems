class Solution {
public:

    vector<int> parent;

    int find(int x) {
        if(parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unionSet(int a, int b) {

        int parentA = find(a);
        int parentB = find(b);

        if(parentA != parentB) {
            parent[parentB] = parentA;
        }
    }

    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

        int n = accounts.size();

        parent.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        unordered_map<string, int> mp;

        // Connect accounts having common emails
        for(int i = 0; i < n; i++) {

            for(int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if(mp.find(email) == mp.end()) {
                    mp[email] = i;
                }
                else {
                    unionSet(i, mp[email]);
                }
            }
        }

        // Group emails according to DSU parent
        map<int, vector<string>> merged;

        for(auto it : mp) {

            string email = it.first;
            int account = it.second;

            int parentAccount = find(account);

            merged[parentAccount].push_back(email);
        }

        // Build answer
        vector<vector<string>> ans;

        for(auto it : merged) {

            int account = it.first;

            vector<string> emails = it.second;

            sort(emails.begin(), emails.end());

            vector<string> temp;

            temp.push_back(accounts[account][0]);

            for(string email : emails) {
                temp.push_back(email);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};