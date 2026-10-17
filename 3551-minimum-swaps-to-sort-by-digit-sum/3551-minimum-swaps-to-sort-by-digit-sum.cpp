class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        auto ds = [](int x) {
            int s = 0;
            while (x) { s += x % 10; x /= 10; }
            return s;
        };

        vector<pair<pair<int,int>, int>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = {{ds(nums[i]), nums[i]}, i};

        sort(v.begin(), v.end());

        vector<bool> vis(n, false);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || v[i].second == i) continue;
            int len = 0, j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = v[j].second;
                len++;
            }
            res += len - 1;
        }
        return res;
    }
};