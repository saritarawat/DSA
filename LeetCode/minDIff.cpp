//{ Driver Code Starts
#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
class Solution
{
private:

int minDiffUtil(int a[], int size, int sumSoFar, int totalSum, vector<vector<int>>& dp)
{
  if(size == 0)
  {
    return abs(totalSum-sumSoFar-sumSoFar);
  }
  if(dp[size][sumSoFar] != -1)
  {
    return dp[size][sumSoFar];
  }
  return dp[size][sumSoFar]=min(minDiffUtil(a, size-1, sumSoFar+a[size-1], totalSum, dp), minDiffUtil(a, size-1, sumSoFar, totalSum, dp)); 
}
public:
  int minDifference(int arr[], int n)
  {
    // Your code goes here
    if(n == 1)
    {
      return arr[0];
    }
    int totalSum = 0;
    for(int i = 0; i < n; ++i)
    {
      totalSum+=arr[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(1000001, -1));
    return minDiffUtil(arr, n, 0, totalSum, dp);
  }
};

//{ Driver Code Starts.
int main()
{
  int vec[] = {1, 6, 11, 5};
  Solution ob;
  cout << ob.minDifference(vec, 4) << "\n";
  return 0;
}
// } Driver Code Ends