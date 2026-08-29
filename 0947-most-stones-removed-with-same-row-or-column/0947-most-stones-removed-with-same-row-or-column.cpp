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

    int removeStones(vector<vector<int>>& stones) {

        int offset = 10001;

        parent.resize(20002);

        for(int i = 0; i < 20002; i++) {
            parent[i] = i;
        }

        vector<int> used(20002, 0);

        for(auto stone : stones) {

            int row = stone[0];
            int col = stone[1] + offset;

            unionSet(row, col);

            used[row] = 1;
            used[col] = 1;
        }

        int components = 0;

        for(int i = 0; i < 20002; i++) {

            if(used[i] == 1 && find(i) == i) {
                components++;
            }
        }

        return stones.size() - components;
    }
};