class Solution {
private:
    vector<int> zero(vector<int>& code, int k){
        int size = code.size();
        vector<int> temp(size,0);
        return temp;
    }
    vector<int> greater(vector<int>& code, int k){
        vector<int> ans(code.size());
        for(int i = 0; i < code.size(); i++){
            int temp = 1;
            int sum = 0;
            while(temp <= k){
                sum += code[(temp + i) % code.size()];
                temp++;
            }
            ans[i] = sum;
        }
        return ans;
    }
    vector<int> less(vector<int>& code, int k){
        vector<int> ans(code.size(), -1);
        cout << "HERE";
        k = -1*k;
        for(int i = 0; i < code.size(); i++){
            int temp = 1;
            int sum = 0;
            while(temp <= k){
                sum += code[(i - temp + code.size()) % code.size()];
                cout << "sum:" << sum << endl;
                temp++;
            }
            ans[i] = sum;
        }
        return ans;
    }
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k < 0){
            return less(code,k);
        }
        if(k == 0){
            return zero(code, k);
        }
        else if(k > 0){
            return greater(code,k);
        }
        else {
            return less(code,k);
        }
    }
};