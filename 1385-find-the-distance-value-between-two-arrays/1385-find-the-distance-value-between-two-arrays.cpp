class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int res = 0;
        for (int x : arr1) {
            auto it = lower_bound(arr2.begin(), arr2.end(), x);
            bool ok = true;
            if (it != arr2.end() && *it - x <= d) ok = false;
            if (ok && it != arr2.begin() && x - *prev(it) <= d) ok = false;
            if (ok) res++;
        }
        return res;
    }
};