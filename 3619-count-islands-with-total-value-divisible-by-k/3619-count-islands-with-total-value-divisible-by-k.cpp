class Solution {
    int m, n;

    long long dfs(vector<vector<int>>& g, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || g[i][j] <= 0) return 0;
        long long sum = g[i][j];
        g[i][j] = -1;
        sum += dfs(g, i + 1, j);
        sum += dfs(g, i - 1, j);
        sum += dfs(g, i, j + 1);
        sum += dfs(g, i, j - 1);
        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long total = dfs(grid, i, j);
                    if (total % k == 0) res++;
                }
            }
        }
        return res;
    }
};