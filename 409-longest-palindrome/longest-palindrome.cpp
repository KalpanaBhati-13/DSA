class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char, int> mp;

        int result =0;
        int oddFreq = 0;

        for(char &ch :s){
            mp[ch]++;
            if(mp[ch]%2!=0){
                oddFreq++;
            }else{
                oddFreq--;
            }
        }
        if(oddFreq > 0){
            return n-oddFreq + 1;
        }
        return n;
    }
};