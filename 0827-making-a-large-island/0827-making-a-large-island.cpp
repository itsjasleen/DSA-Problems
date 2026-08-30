class Solution {
public:

    vector<int> parent;
    vector<int> size;

    int find(int x) {
        if(parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unionSet(int a, int b) {

        int parentA = find(a);
        int parentB = find(b);

        if(parentA == parentB)
            return;

        if(size[parentA] < size[parentB]) {
            parent[parentA] = parentB;
            size[parentB] += size[parentA];
        }
        else {
            parent[parentB] = parentA;
            size[parentA] += size[parentB];
        }
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        parent.resize(n * n);
        size.resize(n * n, 1);

        for(int i = 0; i < n * n; i++) {
            parent[i] = i;
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Step 1: Connect all existing 1s
        for(int r = 0; r < n; r++) {

            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 0)
                    continue;

                int node = r * n + c;

                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < n &&
                       grid[nr][nc] == 1) {

                        int next = nr * n + nc;

                        unionSet(node, next);
                    }
                }
            }
        }

        int ans = 0;

        // Step 2: Try changing every 0 into 1
        for(int r = 0; r < n; r++) {

            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 1)
                    continue;

                set<int> components;

                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < n &&
                       grid[nr][nc] == 1) {

                        int next = nr * n + nc;

                        components.insert(find(next));
                    }
                }

                int currentSize = 1;

                for(int parentNode : components) {
                    currentSize += size[parentNode];
                }

                ans = max(ans, currentSize);
            }
        }

        // In case there is no 0
        for(int i = 0; i < n * n; i++) {
            ans = max(ans, size[find(i)]);
        }

        return ans;
    }
};