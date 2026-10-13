class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> a;

        for (int x : nums) {
            a.push_back(1LL * x * x);
        }

        sort(a.begin(), a.end());

        int n = a.size();
        int positive = (n + 1) / 2;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (i >= n - positive) {
                ans += a[i];
            } else {
                ans -= a[i];
            }
        }

        return ans;
    }
};