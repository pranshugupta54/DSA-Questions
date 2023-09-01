class Solution {
private:
    int helper(vector<int>& cost, int idx, int n, vector<int> &dp){
        if(idx >= n){
            return 0;
        }
        int case1, case2;
        if(dp[idx] != -1){
            return dp[idx];
        }
        if(dp[idx+1] == -1){
            case1 = helper(cost, idx + 1, n, dp);
        } else{
            case1 = dp[idx+1];
        }
        if(dp[idx+2] == -1){
            case2 = helper(cost, idx + 2, n, dp);
        } else{
            case2 = dp[idx+2];
        }
        dp[idx] = cost[idx] + min(case1,case2);
        return dp[idx];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp (cost.size()+3, -1);
        int case1 = helper(cost,0,cost.size(), dp);
        int case2 = helper(cost,1,cost.size(), dp);
        return min(case1,case2);
    }
};