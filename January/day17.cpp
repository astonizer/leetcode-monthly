class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream ss(s);
        string word;
        map<char, string> m;
        set<string> done;
        int i = 0;
        while(ss >> word) {
            if(i == pattern.length())
                return false;
            if(m.find(pattern[i]) == m.end()) {
                if(done.count(word))
                    return false;
                m[pattern[i]] = word;
                done.insert(word);
            }
                if(m[pattern[i]] != word)
                return false;
            i++;
        }
        if(i < pattern.length())
            return false;
        return true;
    }
};
