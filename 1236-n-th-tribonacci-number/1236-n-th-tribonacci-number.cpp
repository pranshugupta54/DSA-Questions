class Solution {
public:
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }
        if(n <= 2){
            return 1;
        }
        int first,second,third;
        first = 0;
        second = 1;
        third = 1;
        for(int i = 3; i < n; i++){
            int sum = first + second + third;
            first = second;
            second = third;
            third = sum;
        }
        return first + second + third;
    }
};