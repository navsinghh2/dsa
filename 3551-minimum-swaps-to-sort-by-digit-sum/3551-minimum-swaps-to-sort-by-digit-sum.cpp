
class Solution {
public:
    int digitSum(int x) {
        int sum = 0;

        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end(), [&](auto a, auto b) {
            int s1 = digitSum(a.first);
            int s2 = digitSum(b.first);

            if (s1 == s2)
                return a.first < b.first;

            return s1 < s2;
        });

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || v[i].second == i)
                continue;

            int cycle = 0;
            int j = i;

            while (!vis[j]) {
                vis[j] = true;
                j = v[j].second;
                cycle++;
            }

            ans += cycle - 1;
        }

        return ans;
    }
};
