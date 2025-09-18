
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool mp[26] = {false};  // initialize all false

        for(char &ch : brokenLetters){
            mp[ch - 'a'] = true;
        }

        int result = 0;
        bool canType = true;

        for(char &ch : text){
            if(ch == ' '){
                if(canType){
                    result++;
                }
                canType = true; // reset for next word
            } else if(mp[ch - 'a']) {
                canType = false;
            }
        }

        // check last word
        if(canType){
            result++;
        }

        return result;
    }
};
