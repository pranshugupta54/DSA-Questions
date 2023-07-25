// 0 10 5 2
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size()-1;
        while(left < right){
            if(left == right){
                break;
            }
            if(arr[left] < arr[left+1]){
                left++;
            }
            if(arr[right] < arr[right-1]){
                right--;
            }
        }
        return right;
    }
};