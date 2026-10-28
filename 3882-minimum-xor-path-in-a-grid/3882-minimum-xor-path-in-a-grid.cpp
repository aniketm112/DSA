class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int B = 1024;
        vector<vector<bitset<B>>> dp(m, vector<bitset<B>>(n));
        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int g = grid[i][j];
                bitset<B> prev;
                if (i > 0) prev |= dp[i - 1][j];
                if (j > 0) prev |= dp[i][j - 1];
                for (int x = 0; x < B; x++)
                    if (prev[x]) dp[i][j][x ^ g] = 1;
            }
        }

        for (int x = 0; x < B; x++)
            if (dp[m - 1][n - 1][x]) return x;
        return -1;
    }
};