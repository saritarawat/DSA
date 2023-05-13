//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{private: 
  int equalPartitionUtil(int arr[], int target, int len, vector<vector<int>>& dp)
  {
    // code here
    if(target == 0)
    {
      return true;
    }
    if(len == 0)
    {
      return false;
    }

    if(dp[len][target] != -1)
    {
      return dp[len][target];
    }

    if(arr[len-1] > target)
    {
      return dp[len][target] = equalPartitionUtil(arr, target, len-1, dp);
    }

    if(equalPartitionUtil(arr, target-arr[len-1], len-1, dp))
    {
      return dp[len][target] = true;
    }

    if(equalPartitionUtil(arr, target, len-1, dp))
    {
      return dp[len][target] = true;
    }
    return dp[len][target] = false;
  }
public:
  int equalPartition(int N, int arr[])
  {
    // code here
    int sum = 0;
    for(int i = 0; i < N; ++i)
    {
      sum+=arr[i];
    }
    if(sum%2 != 0)
    {
      return 0;
    }
    sum = sum/2;
    vector<vector<int>> dp(N+1, vector<int>(sum+1, -1));
    return equalPartitionUtil(arr, sum, N, dp);
  }
};

//{ Driver Code Starts.

int main()
{
  constexpr int N = 3;
  int arr[N] = {1, 3, 5};
  Solution ob;
  if (ob.equalPartition(N, arr))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
// } Driver Code Ends