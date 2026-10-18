class Solution {
    static const long long MOD = 1e9 + 7;
    vector<vector<long long>> C;

    long long solve(vector<int>& v) {
        int n = v.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        for (int i = 1; i < n; i++) {
            if (v[i] < v[0]) left.push_back(v[i]);
            else right.push_back(v[i]);
        }

        long long l = solve(left);
        long long r = solve(right);
        long long ways = C[n - 1][left.size()];
        return ways * l % MOD * r % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        C.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++)
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
        return (solve(nums) - 1 + MOD) % MOD;
    }
};