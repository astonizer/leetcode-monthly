class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> m;
        for(int k=0; k<nums3.size(); k++) {
            for(int l=0; l<nums4.size(); l++) {
                m[nums3[k] + nums4[l]]++;
            }
        }
        
        int ans = 0;
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                ans += m[-nums1[i]-nums2[j]];
            }
        }
        return ans;
    }
};
