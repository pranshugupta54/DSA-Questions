class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for(int i = 0; i< s.length(); i++){
            if(s[i] == 'I'){
                ans += 1;
                if(s[i+1] == 'V' || s[i+1] == 'X'){
                    ans -= 2;
                }
            }
            else if(s[i] == 'X'){
                ans += 10;
                if(s[i+1] == 'L' || s[i+1] == 'C'){
                    ans -= 20;
                }
            }
            else if(s[i] == 'C'){
                ans += 100;
                if(s[i+1] == 'D' || s[i+1] == 'M'){
                    ans -=200;
                }
            }
            else if(s[i] == 'V'){
                ans+= 5;
            }
            else if(s[i] == 'L')
            ans+= 50;
            else if(s[i] == 'D')
            ans+= 500;
            else
            ans+= 1000;
        }
        return ans;
    }
};