class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int best = INT_MAX;

        int k = nums[0];
        bool asc = true;
        for (int i = 0; i < n; i++)
            if (nums[i] != (k + i) % n) { asc = false; break; }
        if (asc) {
            if (k == 0) return 0;
            best = min(best, min(n - k, k + 2));
        }

        int c = nums[0];
        bool desc = true;
        for (int i = 0; i < n; i++)
            if (nums[i] != ((c - i) % n + n) % n) { desc = false; break; }
        if (desc) {
            int kk = (c + 1) % n;
            best = min(best, min(kk + 1, 1 + (n - kk) % n));
        }

        return best == INT_MAX ? -1 : best;
    }
};