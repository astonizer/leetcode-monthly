class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), curr = 0;
        for(int i=0, j=0; i<2*n; i++) {
            curr += gas[i%n] - cost[i%n];
            if(curr < 0) {
                curr = 0;
                j = 0;  // we begin our search from i+1
            } else {
                j++;
                if(j == n)
                    return i-j+1;
            }
        }
        return -1;
    }
};
