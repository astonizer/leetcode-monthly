class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        
        int freq[26] = {0};
        auto found = [&]() {
            for(int i=0; i<26; i++) {
                if(freq[i] != 0) return false;
            }
            return true;
        };
        
        for(int i=0; i<s1.length(); i++) freq[s1[i] - 'a']++, freq[s2[i] - 'a']--;
        if(found()) return true;
        for(int i=s1.length(); i<s2.length(); i++) {
            freq[s2[i] - 'a']--;
            freq[s2[i-s1.length()] - 'a']++;
            if(found()) return true;
        }
        return false;
    }
};
