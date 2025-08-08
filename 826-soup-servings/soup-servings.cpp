
class Solution {
public:
    // Servings in 25ml units instead of ml
    vector<pair<int, int>> serves = {{4, 0}, {3, 1}, {2, 2}, {1, 3}};
    vector<vector<double>> t;

    double solve(int A, int B) {
        // Base cases
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;

        // Memoization check
        if (t[A][B] != -1.0)
            return t[A][B];

        double prob = 0.0;
        for (auto &p : serves) {
            int A_taken = p.first;
            int B_taken = p.second;

            prob += solve(A - A_taken, B - B_taken);
        }

        // Store result before returning
        return t[A][B] = 0.25 * prob;
    }

    double soupServings(int n) {
        //  Optimization for large n
        if (n >= 5000)
            return 1.0;

        //  Convert ml to 25ml units (ceil)
        int m = (n + 24) / 25;

        //  Resize DP table accordingly
        t.resize(m + 1, vector<double>(m + 1, -1.0));

        //  Call solve with reduced units
        return solve(m, m);
    }
};
