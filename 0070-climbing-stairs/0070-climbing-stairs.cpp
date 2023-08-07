class Solution {
    unordered_map<int,int> dp;
public:
    int climbStairs(int n) {
        if(n <= 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }

        if(dp[n]){
            return dp[n];
        }
        dp[n] = climbStairs(n-1) + climbStairs(n-2);
        return dp[n];

    }
};
