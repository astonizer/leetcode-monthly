class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto &v1, auto &v2) {
           return (v1[0]<v2[0]) || (v1[0]==v2[0] && v1[1]>v2[1]); 
        });
        int mx = intervals[0][1], ans = 1;
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][1] > mx) {
                mx = intervals[i][1];
                ans++;
            }
        }
        return ans;
    }
};
