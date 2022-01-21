class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int cnt = 0;
        
        // creating a map to store all visited elements
        vector<int> m(2000);
        
        for(int i=n-1; i>=0; i--) {
            for(int j=1; j<20; j++) {
                if(60*j >= time[i]) {
                    // add the number of occurences
                    cnt += m[60*j - time[i]];
                }
            }
            m[time[i]]++;
        }
        return cnt;
    }
};
