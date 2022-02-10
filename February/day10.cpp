class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, cnt = 0;
        map<int, int> pref;
        pref[0] = 1;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            cnt += pref[sum - k];
            pref[sum]++;
        }
        return cnt;
    }
};
