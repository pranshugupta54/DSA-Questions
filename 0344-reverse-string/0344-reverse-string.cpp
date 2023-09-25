class Solution {
private:
    void helper(vector<char>& str, int left, int right){
        if(left >= right)
            return;
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
        helper(str,left,right);
    }
public:
    void reverseString(vector<char>& s) {
        helper(s, 0, s.size()-1);
    }
};