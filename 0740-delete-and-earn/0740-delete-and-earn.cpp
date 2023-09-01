class Solution {
private: 
    int helper(int arr[], int idx, int size,vector<int> &dp){
        if(idx > size){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        if(arr[idx] == 0){
            return helper(arr,idx+1,size, dp);
        }
        dp[idx] = max(arr[idx]*idx + helper(arr, idx+2, size, dp),helper(arr, idx+1, size, dp));
        return dp[idx];

    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = 0;
        for(int i = 0; i < nums.size(); i++){
            maxNum = max(maxNum, nums[i]);
        }
        int arr[maxNum+2];
        vector<int> dp (maxNum+2, -1);
        for(int i = 0; i < maxNum+2; i++){
            arr[i] = 0;
        }
        for(int i = 0; i < nums.size(); i++){
            arr[nums[i]]++;
        }
        return helper(arr, 0, maxNum+1, dp);


    }
};