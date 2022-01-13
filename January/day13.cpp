class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &v1, auto &v2) {
            return v1[1] < v2[1];
        });
        int hi = points[0][1], arrows = 1, n = points.size();
        for(int i=1; i<n; i++) {
            if(points[i][0] > hi) {
                hi = points[i][1];
                arrows++;
            }
        }
        return arrows;
    }
};
