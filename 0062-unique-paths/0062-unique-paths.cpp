class Solution {
private:
    int helper(int m, int n, int dp[101][101]){
        if(m == 1 || n == 1){
            return 1;
        }
        if(dp[m][n] == -1){
            dp[m][n] = helper(m-1, n, dp) + helper(m,n-1, dp);
        }
        return dp[m][n];
    }
public:
    int uniquePaths(int m, int n) {
        int dp[101][101];
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                dp[i][j] = -1;
            }
        }
        return helper(m,n,dp);
    }
};