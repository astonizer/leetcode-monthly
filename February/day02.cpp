class Solution {
    bool check(int freq[]) {
        for(int i=0; i<26; i++) if(freq[i] != 0) return false;
        return true;
    }
    
public:
    vector<int> findAnagrams(string s, string p) {
        int freq[26] = {0}, k = p.length();
        if(s.length() < k) return {};
        for(int i=0; i<k; i++) freq[p[i] - 'a']++;
        for(int i=0; i<k; i++) freq[s[i] - 'a']--;
        vector<int> ans;
        if(check(freq)) ans.push_back(0);
        int l = 1, r = k;
        while(r<s.length()) {
            freq[s[l-1]-'a']++;
            freq[s[r]-'a']--;
            if(check(freq)) ans.push_back(l);
            l++, r++;
        }
        return ans;
    }
};
