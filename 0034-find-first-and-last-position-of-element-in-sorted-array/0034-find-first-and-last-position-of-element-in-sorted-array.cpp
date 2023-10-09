class Solution {
private:
    int first(vector<int>& nums, int target, int start, int end){
        if(start > end){
            return -1;
        }
        int n = end-start+1;
        int mid = (start+end)/2;
        // if(n % 2 == 0){
        //     mid--;
        // }
        if(nums[mid] < target){
            return first(nums, target, mid+1, end);
        }
        if(nums[mid] == target){
            int temp = first(nums,target,start, mid-1);
            if(temp != -1){
                return temp;
            } else {
                return mid;
            }
        }
        else{
            return first(nums, target, start, mid-1);
        }
    }
    int second(vector<int>& nums, int target, int start, int end){
        if(start > end){
            return -1;
        }
        int n = end-start+1;
        int mid = (start+end)/2;
        // if(n % 2 == 0){
        //     mid--;
        // }
        if(nums[mid] < target){
            return second(nums, target, mid+1, end);
        }
        if(nums[mid] == target){
            int temp = second(nums,target,mid+1, end);
            if(temp != -1){
                return temp;
            } else {
                return mid;
            }
        }
        else{
            return second(nums, target, start, mid-1);
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = first(nums, target, 0, nums.size()-1);
        int s = second(nums, target, 0, nums.size()-1);
        vector<int> ans;
        ans.push_back(f);
        ans.push_back(s);
        // ans.push_back(-1);
        return ans;
    }
};