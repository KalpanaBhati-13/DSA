
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;
        int n = basket1.size();

        for (int i = 0; i < n; ++i) {
            freq[basket1[i]]++;
            freq[basket2[i]]--;
        }

        vector<int> toSwap;
        int minVal = INT_MAX;

        for (auto& [num, count] : freq) {
            if (count % 2 != 0) return -1;  // Uneven frequency => not possible
            int half = abs(count) / 2;

            for (int i = 0; i < half; ++i)
                toSwap.push_back(num);

            minVal = min(minVal, num);
        }

        sort(toSwap.begin(), toSwap.end());

        long long cost = 0;
        int m = toSwap.size();
        for (int i = 0; i < m / 2; ++i) {
            cost += min(toSwap[i], 2 * minVal);
        }

        return cost;
    }
};
