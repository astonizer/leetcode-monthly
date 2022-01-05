class Solution {
    vector<vector<string>> ans;
    
    bool isPal(string &s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--]) 
                return false;
        }
        return true;
    }
    
    void part(vector<string> v, string &s, int i) {
        int n = s.length();
        if(i == n) {
            ans.push_back(v);
            return;
        }
        
        for(int j=i; j<n; j++) {
            if(isPal(s, i, j)) {
                v.push_back(s.substr(i, j-i+1));
                part(v, s, j+1);
                v.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<string> v;
        part(v, s, 0);
        return ans;
    }
};
