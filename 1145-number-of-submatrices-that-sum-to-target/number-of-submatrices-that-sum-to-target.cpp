class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Row-wise prefix sum
        for (int row = 0; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                matrix[row][col] += matrix[row][col - 1];
            }
        }

        int result = 0;
        // Iterate over all column pairs
        for (int startCol = 0; startCol < cols; startCol++) {
            for (int j = startCol; j < cols; j++) {
                unordered_map<int, int> mp;
                mp[0] = 1; // Base case
                int cumSum = 0;

                for (int row = 0; row < rows; row++) {
                    cumSum += matrix[row][j] - (startCol > 0 ? matrix[row][startCol - 1] : 0);
                    if (mp.find(cumSum - target) != mp.end()) {
                        result += mp[cumSum - target];
                    }
                    mp[cumSum]++;
                }
            }
        }
        return result;
    }
};
