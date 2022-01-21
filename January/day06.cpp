class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int passengers[1001] = {0};
        for(auto &v: trips) {
            passengers[v[1]] += v[0];
            passengers[v[2]] -= v[0];
        }
        for(int i=0; i<1001; i++) {
            if(i) passengers[i] += passengers[i-1];
            if(passengers[i] > capacity) return false;
        }
        return true;
    }
};
