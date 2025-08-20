
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0) return 0;

        // prev[t][0/1/2], curr[t][0/1/2]
        vector<vector<long long>> prev(k+1, vector<long long>(3, 0)), curr(k+1, vector<long long>(3, 0));

        for (int t = 0; t <= k; t++) {
            prev[t][0] = 0;
            prev[t][1] = -prices[0];  // buy on day 0
            prev[t][2] = prices[0];   // short sell on day 0
        }

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= k; t++) {
                curr[t][0] = max({prev[t][0], prev[t][1] + prices[i], prev[t][2] - prices[i]});
                curr[t][1] = max(prev[t][1], prev[t-1][0] - prices[i]);
                curr[t][2] = max(prev[t][2], prev[t-1][0] + prices[i]);
            }
            prev = curr;  // move to next day
        }

        return prev[k][0];
    }
};


