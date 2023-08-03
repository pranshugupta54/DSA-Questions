//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
private: 
    void helper(stack<int> &S1, stack<int> &S2){
        if(S1.size() != 0){
            S2.push(S1.top());
            S1.pop();
            helper(S1,S2);
        }
        return;
    }
public:
    void Reverse(stack<int> &St){
        stack<int> temp;
        helper(St,temp);
        St = temp;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends