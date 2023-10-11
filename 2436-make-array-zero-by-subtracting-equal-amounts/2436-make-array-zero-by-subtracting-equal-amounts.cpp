class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> myset;
        bool zero = false;
        for(int i = 0; i < nums.size(); i++){
            myset.insert(nums[i]);
            if(nums[i] == 0){
                zero = true;
            }
        }
        if(zero){
            return myset.size() - 1;
        }
        return myset.size();
    }
};