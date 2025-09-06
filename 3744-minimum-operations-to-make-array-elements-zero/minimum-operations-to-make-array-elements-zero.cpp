
class Solution {
public:
    long long solve(int l, int r) {
        long long L = 1;   // left boundary of the "level"
        long long S = 1;   // step count (level depth)
        long long steps = 0;

        while (L <= r) {
            long long R = 4 * L - 1;   // right boundary of this level
            long long start = max(L, (long long)l);
            long long end = min(R, (long long)r);

            if (start <= end) {
                steps += (end - start + 1) * S;   // contribution of this level
            }

            S += 1;       // move to next level
            L = L * 4;    // next level’s left boundary
        }
        return steps;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;

        for (auto &query : queries) {
            int l = query[0];
            int r = query[1];

            long long steps = solve(l, r);
            result += (steps + 1) / 2;   // ceil(steps / 2)
        }
        return result;
    }
};
