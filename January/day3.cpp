class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m = trust.size();
        vector<int> in(n), out(n);
      
        for(int i=0; i<m; i++) {
            in[trust[i][1] - 1]++;
            out[trust[i][0] - 1]++;
        }
      
        // find the person who is trusted by every other and doesn't trust anyone
        for(int i=0; i<n; i++) {
            if(in[i] == n-1 && out[i] == 0) {
                return i+1;
            }
        }
        return -1;
    }
};
