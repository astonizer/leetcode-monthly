class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> st;
        int cnt = 0, l = 0, r = 1;
        while(r<nums.size()) {
            int a = abs(nums[r] - nums[l]);
            if(a == k) {
                if(!st.count({nums[l], nums[r]}) && !st.count({nums[r], nums[l]})) {
                    cnt++;
                    st.insert({nums[l], nums[r]});
                }   
                l++, r++;
            } else if(a < k) r++;
            else l++;
            
            r = max(r, l+1);
        }
        return cnt;
    }
};
