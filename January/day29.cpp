class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<vector<int>> stretch(n, vector<int>(2, 1));
        stack<pair<int, int>> st;
        
        int i = n - 1;
        st.push({heights[i], i});
        stretch[i][1] = 1;
        while(--i>=0) {
            while(st.size() && st.top().first>=heights[i]) {
                int j = st.top().second;
                st.pop();
                stretch[i][1] = max(stretch[i][1], j - i + stretch[j][1]);
            }
            st.push({heights[i], i});
        }
        while(!st.empty()) st.pop();
        
        i = 0;
        st.push({heights[i], i});
        stretch[i][0] = 1;
        while(++i<n) {
            while(st.size() && st.top().first>=heights[i]) {
                int j = st.top().second;
                st.pop();
                stretch[i][0] = max(stretch[i][0], i - j + stretch[j][0]);
            }
            st.push({heights[i], i});
        }
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            ans = max(ans, heights[i]*(stretch[i][0] + stretch[i][1] - 1));
        }
        cout << endl;
        return ans;
    }
};
