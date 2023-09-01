class Solution {

private:
int helper(int n){
    if(n == 0){
        return 0;
    }
    while(n % 2 == 0){
        n = n/2;
    }
    return n;
}
int count(int n){
    int ans = 0;
    while(n > 0){
        if(n % 2 == 1){
            ans++;
        }
        n = n/2;
    }
    return ans;
}

public:
    vector<int> countBits(int n) {
        unordered_map<int,int> mp;
        vector<int> v;
        for(int i = 0; i <= n; i++){
            int term = helper(i);
            int temp;
            if(mp.find(term) != mp.end()){
                temp = mp[term];
            }
            else{
                temp = count(term);
                mp[term] = temp;
            }
            v.push_back(mp[term]);
        }
        return v;
    }
};