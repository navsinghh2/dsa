class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;
            int prevMax = -1;

            for (int i = 0; i < n; i += k) {
                int desc = 0;
                int mn = nums[i], mx = nums[i];

                for (int j = 0; j < k; j++) {
                    int cur = nums[i + j];
                    int next = nums[i + (j + 1) % k];

                    mn = min(mn, cur);
                    mx = max(mx, cur);

                    if (cur > next) desc++;
                }

                if (desc > 1 || (prevMax != -1 && prevMax > mn)) {
                    ok = false;
                    break;
                }

                prevMax = mx;
            }

            if (ok) ans += k;
        }

        return ans;
    }
};