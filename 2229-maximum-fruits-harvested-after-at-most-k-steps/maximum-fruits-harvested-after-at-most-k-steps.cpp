
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos(n), amount(n);
        for (int i = 0; i < n; ++i) {
            pos[i] = fruits[i][0];
            amount[i] = fruits[i][1];
        }

        int ans = 0, currSum = 0;
        int l = 0;

        // Right bound: moving from l to r
        for (int r = 0; r < n; ++r) {
            currSum += amount[r];

            // Move left pointer if total steps exceed k
            while (l <= r && !canReach(pos, startPos, k, l, r)) {
                currSum -= amount[l++];
            }

            ans = max(ans, currSum);
        }

        return ans;
    }

    // Helper: Check if range [l..r] can be visited from startPos within k steps
    bool canReach(vector<int>& pos, int startPos, int k, int l, int r) {
        int left = pos[l], right = pos[r];

        // Two possible paths:
        // 1. go left first, then to right
        // 2. go right first, then to left
        int step1 = abs(startPos - left) + (right - left);
        int step2 = abs(startPos - right) + (right - left);

        return min(step1, step2) <= k;
    }
};
