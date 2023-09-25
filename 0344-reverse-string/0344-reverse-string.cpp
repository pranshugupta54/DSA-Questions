class Solution {
private:
    void helper(vector<char>& str, int left, int right, char temp){
        if(left >= right)
            return;
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
        helper(str,left,right, temp);
    }
public:
    void reverseString(vector<char>& s) {
        char temp;
        helper(s, 0, s.size()-1, temp);
    }
};