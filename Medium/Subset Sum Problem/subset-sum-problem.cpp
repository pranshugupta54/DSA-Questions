//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
private:
    int helper(vector<int> arr, int sum,vector<vector<int>>& dp){
        if(arr.size() == 0){
            if(sum == 0){
                return 1;
            } else return 0;
        }
        if(dp[arr.size()][sum] != -1){
            return dp[arr.size()][sum];
        }
        if(arr[0] > sum){
            dp[arr.size()][sum] = helper(vector<int>(arr.begin() + 1, arr.end()), sum, dp);
        }
        else{
            dp[arr.size()][sum] = helper(vector<int>(arr.begin() + 1, arr.end()), sum, dp) || helper(vector<int>(arr.begin() + 1, arr.end()), sum-arr[0], dp);
        }
        return dp[arr.size()][sum];
        
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));  
        return helper(arr,sum, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends