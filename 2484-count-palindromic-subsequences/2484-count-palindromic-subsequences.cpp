
class Solution {
public:
    int countPalindromes(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        long long left[10] = {};
        long long right[10] = {};
        long long leftPairs[10][10] = {};
        long long rightPairs[10][10] = {};

        for (int i = n - 1; i >= 0; i--) {
            int d = s[i] - '0';
            for (int a = 0; a < 10; a++) {
                rightPairs[d][a] += right[a];
            }
            right[d]++;
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            right[d]--;

            for (int a = 0; a < 10; a++) {
                rightPairs[d][a] -= right[a];
            }

            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    ans = (ans + leftPairs[a][b] * rightPairs[b][a]) % MOD;
                }
            }

            for (int a = 0; a < 10; a++) {
                leftPairs[a][d] += left[a];
            }
            left[d]++;
        }

        return ans;
    }
};
