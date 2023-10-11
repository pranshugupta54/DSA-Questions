class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> myset;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                continue;
            }
            myset.insert(nums[i]);
        }
        return myset.size();
    }
};