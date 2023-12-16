//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    int helper(int arr[], int n, int sum, vector<vector<int>> &dp){
        if(sum < 0)
            return 0;
        if(sum == 0){
            return 1;
        }
        if(n == 1){
            if(sum == arr[0]){
                return 1;
            }
            return 0;
        }
        if(dp[n][sum] == -1){
            dp[n][sum] = (helper(arr+1, n-1, sum - arr[0], dp) + helper(arr+1, n-1, sum,dp))% 1000000007;
        }
        return dp[n][sum];
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
	    int zeros = 0;
        // Your code goes here
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                zeros++;
            }
        }
        sort(arr, arr+n);
        return pow(2,zeros)*helper(arr+zeros,n-zeros,sum, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends