class Solution {
private:
    int helper(vector<int>& cost, int idx, int n, vector<int> &dp){
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        dp[idx] = cost[idx] + min(helper(cost, idx + 1, n, dp),helper(cost, idx + 2, n, dp));
        return dp[idx];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp (cost.size()+3, -1);
        return min(helper(cost,0,cost.size(), dp),helper(cost,1,cost.size(), dp));
    }
};