class Solution {
public:

    vector<int> parent;

    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unionSet(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);

        if(parentA != parentB) {
            parent[parentB] = parentA;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        parent.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // email -> account index
        unordered_map<string, int> mp;

        // Connect accounts having common emails
        for(int i = 0; i < n; i++) {

            for(int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if(mp.find(email) == mp.end()) {

                    // First time seeing this email
                    mp[email] = i;
                }
                else {

                    // Email already belongs to another account
                    unionSet(i, mp[email]);
                }
            }
        }

        // Store emails according to their parent
        vector<vector<string>> merged(n);

        for(auto it : mp) {

            string email = it.first;
            int account = it.second;

            int parentAccount = find(account);

            merged[parentAccount].push_back(email);
        }

        vector<vector<string>> ans;

        // Create final accounts
        for(int i = 0; i < n; i++) {

            if(merged[i].size() == 0)
                continue;

            sort(merged[i].begin(), merged[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);  // name

            for(auto email : merged[i]) {
                temp.push_back(email);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};