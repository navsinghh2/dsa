class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
      int n = arr.size();
        vector<int> best(n, 1000000);

        int left = 0;
        int sum = 0;
        int ans = 1000000;
        int minLen = 1000000;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {

                int len = right - left + 1;

                if (left > 0 && best[left - 1] != 1000000) {
                    ans = min(ans, len + best[left - 1]);
                }

                minLen = min(minLen, len);
            }

            if (right == 0) {
                best[right] = minLen;
            }
            else {
                best[right] = min(best[right - 1], minLen);
            }
        }

        if (ans == 1000000)
            return -1;

        return ans;
    }
};