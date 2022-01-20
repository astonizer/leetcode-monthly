class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dp[n][m][m], ans = 0;
        memset(dp, 0, sizeof(dp));
        dp[0][0][m-1] = grid[0][0] + grid[0][m-1];
        for(int i=1; i<n; i++) {
            for(int j=0; j<min(m, i+1); j++) {
                for(int k=max(0, m-i-1); k<m; k++) {
                    for(int p=max(j-1,0); p<=min(j+1,m-1); p++) {
                        for(int q=max(k-1,0); q<=min(k+1,m-1); q++) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][p][q]);
                        }
                    }
                    dp[i][j][k] += grid[i][j] + (j==k?0:grid[i][k]);
                    if(i == n-1)
                        ans = max(ans, dp[i][j][k]);
                }
            }
        }
        return ans;
    }
};
