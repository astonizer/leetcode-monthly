class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), s = 0, len = 0;
        map<int, int> m;
        for(int i=0; i<n; i++) {
            if(nums[i]) s++;
            else s--;
            
            if(m[s]) len = max(len, i - m[s] + 1);
            else if(s == 0) len = max(len, i+1);
            else m[s] = i+1;
        }
        return len;
    }
};
