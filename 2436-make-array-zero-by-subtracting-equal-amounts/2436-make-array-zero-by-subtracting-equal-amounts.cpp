class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1;
        
        int prev = nums[0];
        if(prev == 0){
            count--;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                continue;
            }
            if(prev == nums[i]){
                continue;
            }
            else{
                count++;
                prev = nums[i];
            }
        }
        return count;
    }
};