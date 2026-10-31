class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> R(m + 2, vector<long long>(n + 2, 0));
        vector<vector<long long>> D(m + 2, vector<long long>(n + 2, 0));
        R[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                R[i][j] %= MOD;
                D[i][j] %= MOD;
                if (grid[i][j] == 0) {
                    if (i == m - 1 && j == n - 1) return (R[i][j] + D[i][j]) % MOD;
                    long long w = (R[i][j] + D[i][j]) % MOD;
                    R[i][j + 1] += w;
                    D[i + 1][j] += w;
                } else {
                    D[i + 1][j] += R[i][j];
                    R[i][j + 1] += D[i][j];
                }
            }
        }
        return 0;
    }
};