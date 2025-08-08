
class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        int n = s.length();
        int i = 0, r = 0;

        while (i < n) {
            // Skip multiple spaces
            while (i < n && s[i] == ' ') i++;

            if (i >= n) break;

            // Add a space between words (except the first)
            if (r != 0) s[r++] = ' ';

            // Start of the word
            int start = r;

            // Copy word to the front
            while (i < n && s[i] != ' ') {
                s[r++] = s[i++];
            }

            // Reverse the word in place
            reverse(s.begin() + start, s.begin() + r);
        }

        // Resize the string to remove trailing characters
        s.resize(r);

        return s;
    }
};
