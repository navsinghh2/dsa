
class Solution {
public:
    const int MOD = 1000000007;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b % 2 == 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b /= 2;
        }

        return ans;
    }

    int numberOfSets(int n, int k) {
        if (k > n - 1)
            return 0;

        int N = n + k - 1;
        int R = 2 * k;

        long long numerator = 1;
        long long denominator = 1;

        for (int i = 1; i <= N; i++)
            numerator = numerator * i % MOD;

        for (int i = 1; i <= R; i++)
            denominator = denominator * i % MOD;

        for (int i = 1; i <= N - R; i++)
            denominator = denominator * i % MOD;

        long long inverse = power(denominator, MOD - 2);

        return numerator * inverse % MOD;
    }
};