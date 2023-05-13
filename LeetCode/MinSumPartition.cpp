//{ Driver Code Starts
#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
  int minDifferenceUtil(int arr[], int len, int s1, int total, int& minVal, vector<vector<int>>& dp)
  {
    // Your code goes here
    if(len == 0)
    {
      return abs(total-2*s1);
    }
    if(dp[len][s1] != -1)
    {
      return dp[len][s1];
    }
    minVal = min(minVal,minDifferenceUtil(arr, len-1, s1+arr[len-1], total, minVal, dp));
    minVal = min(minVal,minDifferenceUtil(arr, len-1, s1, total, minVal, dp));
    return dp[len][s1] = minVal;
  }
public:
  int minDifference(int arr[], int n)
  {
    // Your code goes here
    int minVal = INT_MAX;
    int total = 0;
    for(int i = 0; i < n; ++i)
    {
      total+=arr[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(total+1, -1));
    minDifferenceUtil(arr, n, 0, total, minVal, dp);
    return minVal;
  }
};

//{ Driver Code Starts.
int main()
{
  const int n = 4;
  int a[n] = {1, 6, 11, 5};
  Solution ob;
  cout << ob.minDifference(a, n) << "\n";
  return 0;
}
// } Driver Code Ends