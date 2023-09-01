class Solution {
private:
    int helper(vector<int>& nums, int idx, vector<int> &dp){
        if(idx >= nums.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int case1 = nums[idx] + helper(nums, idx+2, dp);
        int case2 = helper(nums,idx+1, dp);
        dp[idx] = max(case1,case2);
        return dp[idx];
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp (nums.size()+3, -1);
        return helper(nums,0, dp);
    }
};