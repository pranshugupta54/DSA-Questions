//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool helper(int N, int arr[], int sum1, int sum2,  vector<vector<int>> &dp){
        if(N == 0){
            if(sum1==sum2)
                return true;
            return false;
        }
        if(dp[N][sum1] == -1){
            dp[N][sum1] = helper(N-1, arr, sum1 + arr[N-1], sum2, dp) || helper(N-1, arr, sum1, sum2+arr[N-1], dp);
        }
        return dp[N][sum1];
    }
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i = 0; i < N; i++){
            sum += arr[i];
        }
        vector<vector<int>> dp(N + 1, vector<int>(sum + 1, -1));
        return helper(N, arr, 0, 0, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends