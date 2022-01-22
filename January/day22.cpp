class Solution {
public:
    bool winnerSquareGame(int n) {
        bool dp[n+1];
        dp[0] = false;
        for(int i=1; i<=n; i++) {
            dp[i] = false;
            for(int j=1; j<=315 && i>=j*j && !dp[i]; j++) {
                dp[i] |= !dp[i-j*j];
            }
        }
        return dp[n];
    }
};
