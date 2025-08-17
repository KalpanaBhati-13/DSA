
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // If Alice never draws (k == 0) or even the worst-case (k-1 + maxPts) can't exceed n,
        // then probability is 1.
        if (k == 0 || n >= k - 1 + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        double windowSum = 1.0; // sum of dp[i-1], dp[i-2], ..., dp[i-maxPts] (but only indices < k)
        double ans = 0.0;

        for (int i = 1; i <= n; ++i) {
            dp[i] = windowSum / maxPts;

            if (i < k) {
                // Still drawing phase: dp[i] contributes to future states
                windowSum += dp[i];
            } else {
                // Stopped drawing (i >= k): accumulate into the final answer
                ans += dp[i];
            }

            // Remove the term that falls out of the window (only if it was in "drawing" range)
            int j = i - maxPts;
            if (j >= 0 && j < k) {
                windowSum -= dp[j];
            }
        }
        return ans;
    }
};
