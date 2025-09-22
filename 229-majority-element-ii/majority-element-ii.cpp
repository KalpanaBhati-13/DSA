
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        // 2 candidates (क्योंकि n/3 case में max 2 majority elements हो सकते हैं)
        int cand1 = 0, cand2 = 0;
        int freq1 = 0, freq2 = 0;

        // Step 1: Find candidates
        for (int num : nums) {
            if (num == cand1) {
                freq1++;
            } 
            else if (num == cand2) {
                freq2++;
            } 
            else if (freq1 == 0) {
                cand1 = num;
                freq1 = 1;
            } 
            else if (freq2 == 0) {
                cand2 = num;
                freq2 = 1;
            } 
            else {
                freq1--;
                freq2--;
            }
        }

        // Step 2: Verify candidates
        freq1 = freq2 = 0;
        for (int num : nums) {
            if (num == cand1) freq1++;
            else if (num == cand2) freq2++;
        }

        // Step 3: Collect results
        vector<int> ans;
        if (freq1 > n / 3) ans.push_back(cand1);
        if (freq2 > n / 3) ans.push_back(cand2);

        return ans;
    }
};
