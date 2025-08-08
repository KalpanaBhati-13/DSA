class Solution {
    bool checkEqual(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        int count1[26] = {0};
        for (char c : s1) {
            count1[c - 'a']++;
        }

        int windowsize = s1.length();
        int count2[26] = {0};

        int i = 0;

        // First window
        while (i < windowsize) {
            count2[s2[i] - 'a']++;
            i++;
        }

        if (checkEqual(count1, count2))
            return true;

        // Slide the window
        while (i < s2.length()) {
            char newChar = s2[i];
            count2[newChar - 'a']++;

            char oldChar = s2[i - windowsize];
            count2[oldChar - 'a']--;

            if (checkEqual(count1, count2))
                return true;

            i++;
        }

        return false;
    }
};

