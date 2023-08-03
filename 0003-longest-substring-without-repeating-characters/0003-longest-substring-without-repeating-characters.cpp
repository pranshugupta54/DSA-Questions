class Solution {
public:
    int lengthOfLongestSubstring(string s) {
   
        if(s[0]=='\0' ){
            return 0;
        }


     vector<int>v(128,0);
     int count=0;
     for (int i=0;i<s.length();i++){
        if(v[s[i]]!=0){
            break;
        }
         v[s[i]]++;
         count++;
     }
     int temp=lengthOfLongestSubstring(s.substr(1));
     return max(temp,count);
   
     
    }
};