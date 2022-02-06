class Solution {
    void reverse(vector<int> &nums, int l, int r) {
        while(l < r) swap(nums[l++], nums[r--]);
    }
    
    void rotate(vector<int> &nums, int l, int k) {
        int n = nums.size() - 1;
        reverse(nums, l, n);
        reverse(nums, l, n-k);
        reverse(nums, n-k+1, n);
    }
    
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1, n = nums.size(), k = 1;
        for(int i=1; i<n; i++) {
            if(nums[i] == nums[i-1]) cnt++;
            else if(nums[i] < nums[i-1]) break;
            else cnt = 1;
            k++;
            
            if(cnt == 3) {
                k--;
                int j = i+1;
                while(j<n && nums[j] == nums[j-1]) j++;
                rotate(nums, i, j-i);
                if(j < n) i--;
                else i = j;
            }
        }
        return k;
    }
};
