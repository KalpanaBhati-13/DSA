class Solution {
public:
    int removePattern(string &s, char first, char second, int score) {
        stack<char> st;
        int total = 0;

        for (char c : s) {
            if (!st.empty() && st.top() == first && c == second) {
                st.pop();
                total += score;
            } else {
                st.push(c);
            }
        }

        // Construct the remaining string
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return total;
    }

    int maximumGain(string s, int x, int y) {
        int total = 0;

        if (x > y) {
            // Remove "ab" first
            total += removePattern(s, 'a', 'b', x);
            total += removePattern(s, 'b', 'a', y);
        } else {
            // Remove "ba" first
            total += removePattern(s, 'b', 'a', y);
            total += removePattern(s, 'a', 'b', x);
        }

        return total;
    }
};
