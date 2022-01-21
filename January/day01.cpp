class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n];
        for(int gap=0; gap<n; gap++) {
            for(int i=0, j=gap; j<n; i++, j++) {
                dp[i][j] = 0;
                for(int k=i; k<=j; k++) {
                    int leftOfWindow = (k>i?dp[i][k-1]:0);
                    int rightOfWindow = (k<j?dp[k+1][j]:0);
                    int leftInWindow = (i>0?nums[i-1]:1);
                    int rightInWindow = (j<n-1?nums[j+1]:1);
                    dp[i][j] = max(
                        dp[i][j],
                        leftOfWindow + rightOfWindow + leftInWindow*nums[k]*rightInWindow
                    );
                }
            }
        }
        return dp[0][n-1];
    }
};
