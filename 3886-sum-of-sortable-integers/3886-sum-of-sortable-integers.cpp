class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k) continue;
            bool ok = true;
            int prevMax = INT_MIN;
            for (int l = 0; l < n && ok; l += k) {
                int r = l + k - 1;
                int inner = 0, p = -1;
                for (int i = l; i < r; i++) {
                    if (nums[i] > nums[i + 1]) {
                        inner++;
                        p = i;
                    }
                }
                int wrap = nums[r] > nums[l] ? 1 : 0;
                if (inner + wrap > 1) { ok = false; break; }

                int mn, mx;
                if (inner == 1) {
                    mn = nums[p + 1];
                    mx = nums[p];
                } else {
                    mn = nums[l];
                    mx = nums[r];
                }
                if (prevMax > mn) { ok = false; break; }
                prevMax = mx;
            }
            if (ok) res += k;
        }
        return res;
    }
};