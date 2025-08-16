
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '6'){     // first '6' ko '9' me change karo
                s[i] = '9';
                break;
            }
        }
        
        return stoi(s);
    }
};
