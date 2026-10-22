class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int pos = 0;

        while (nums[pos] != 0) {
            pos++;
        }

        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != i) {
                ok = false;
                break;
            }
        }

        if (ok) {
            return min(pos, n - pos + 2);
        }

        pos = 0;

        while (nums[pos] != n - 1) {
            pos++;
        }

        ok = true;

        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != n - 1 - i) {
                ok = false;
                break;
            }
        }

        if (ok) {
            return 1 + min(pos, n - pos);
        }

        return -1;
    }
};