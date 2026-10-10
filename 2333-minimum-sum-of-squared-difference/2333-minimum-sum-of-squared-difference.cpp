class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<long long> cnt(100001, 0);

        for (int i = 0; i < n; i++)
            cnt[abs(nums1[i] - nums2[i])]++;

        for (int d = 100000; d >= 1 && k > 0; d--) {
            long long m = min(cnt[d], k);
            cnt[d] -= m;
            cnt[d - 1] += m;
            k -= m;
        }

        long long res = 0;
        for (long long d = 1; d <= 100000; d++)
            res += cnt[d] * d * d;
        return res;
    }
};