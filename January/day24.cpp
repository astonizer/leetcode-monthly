class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length(), caps = 0;
        for(char c: word) {
            if(c <= 'Z') {
                caps++;
            }
        }
        return caps==0 || caps==n || caps==1 && word[0]<='Z';
    }
};
