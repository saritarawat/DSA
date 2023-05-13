//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// } Driver Code Ends
class Solution
{
  const int MOD = 1000000007;
int perfectSumUtil(int arr[], int target, int len, vector<vector<int>>& dp)
  {
    // code here
    if(target == 0 && len == 0)
    {
      return 1;
    }
    if(len == 0)
    {
      return 0;
    }

    if(dp[len][target] != -1)
    {
      return dp[len][target];
    }


    if(arr[len-1] > target)
    {
      return dp[len][target] = perfectSumUtil(arr, target, len-1, dp)%MOD;
    }

    return dp[len][target] = (perfectSumUtil(arr, target-arr[len-1], len-1, dp)%MOD + perfectSumUtil(arr, target, len-1, dp)%MOD)%MOD;
  }

public:
  int perfectSum(int arr[], int n, int sum)
  {
    // Your code goes here
    //sort(arr, arr+n);
    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
    return perfectSumUtil(arr, sum, n, dp);
  }
};

//{ Driver Code Starts.
int main()
{
  const int n = 10;
  int sum = 31;

  int a[n] = {9, 7, 0, 3, 9, 8, 6, 5, 7, 6};

  Solution ob;
  cout << "sum: "<<ob.perfectSum(a, n, sum) << endl;
  return 0;
}

// } Driver Code Ends