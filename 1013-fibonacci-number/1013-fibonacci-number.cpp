#include <unordered_map>

class Solution {
    std::unordered_map<int, int> dp;

public:
    Solution() {
        dp[0] = 0;
        dp[1] = 1;
    }

    int fib(int n) {
        if(n == 0 || n == 1){
            return n;
        }
        int first, second;
        if (dp.find(n - 1) != dp.end()) {
            second = dp[n - 1];
        } else {
            second = fib(n - 1);
        }
        if (dp.find(n - 2) != dp.end()) {
            first = dp[n - 2];
        } else {
            first = fib(n - 2);
        }
        dp[n] = first + second;
        return dp[n];
    }
};
