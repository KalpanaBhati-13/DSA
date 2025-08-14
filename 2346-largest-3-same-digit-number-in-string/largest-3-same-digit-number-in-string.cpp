
class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        char maxChar = 0; // use 0 so we can compare properly

        for (int i = 2; i < n; i++) {
            if (num[i] == num[i-1] && num[i] == num[i-2]) {
                maxChar = max(maxChar, num[i]);
            }
        }
        
        if (maxChar == 0) {
            return "";
        }
        return string(3, maxChar);
    }
};
