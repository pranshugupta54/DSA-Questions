class Solution {
private:
    bool helper2(string str, int num){
        int size = str.length();
        if(size == 0){
            return 0;
        }
        if(size == 1){
            if(stoi(str) == num)
            return true;
            else return false;
        } 
          try {
            if (stoi(str) == num) {
                return true;
            }
        } catch (const std::invalid_argument& e) {
            // Handle the invalid argument exception
            cout << "str:" << str <<endl;
            return false;
        }
        for(int i = 1; i <= size; i++){
            string first = str.substr(0, i);
            string two = str.substr(i, size-i);
            int temp = stoi(first);
            if (temp > num) {
                break;
            }
            // cout << "temp:"<< temp<<endl;
            if(helper2(two, num-temp)){
                return true;
            }
            // cout << "--"<<endl;
        }
        return false;
    }
    bool helper(int n){
        int sq = n*n;
        string str = to_string(sq);
        return helper2(str, n);
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(helper(i)){
                cout << i << endl;
                ans += i*i;
            }
        }
        return ans;
    }
};