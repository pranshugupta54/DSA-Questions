class Solution {
private:
    int helper(vector<vector<int>>& grid, int x, int y,int dp[201][201]){
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        if(x == (grid.size()-1) && y == (grid[0].size()-1)){
            return grid[x][y];
        }
        if(x == grid.size()-1){
            return grid[x][y] + helper(grid,x,y+1, dp);
        }
        if(y == grid[0].size()-1){
            return grid[x][y] + helper(grid,x+1,y, dp);
        }
        dp[x][y] = grid[x][y] + min(helper(grid,x+1,y,dp), helper(grid, x, y+1,dp));
        return dp[x][y];

    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dp[201][201];
        for (int i = 0; i < 201; i++) {
            for (int j = 0; j < 201; j++) {
                dp[i][j] = -1;
            }
        }
        return helper(grid, 0, 0, dp);
    }
};