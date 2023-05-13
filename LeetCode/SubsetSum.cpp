//{ Driver Code Starts
// Initial template for C++

#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
  private:
  bool isSubsetSumUtil(vector<int> arr, int target, int len, vector<vector<int>>& dp)
  {
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
      return dp[len][target] = isSubsetSumUtil(arr, target, len-1, dp);
    }

    if(isSubsetSumUtil(arr, target-arr[len-1], len-1, dp))
    {
      return dp[len][target] = true;
    }

    if(isSubsetSumUtil(arr, target, len-1, dp))
    {
      return dp[len][target] = true;
    }
    return dp[len][target] = false;
  }
public:
  bool isSubsetSum(vector<int> arr, int sum)
  {
    vector<vector<int>> dp(arr.size()+1, vector<int>(sum+1, -1));
    return isSubsetSumUtil(arr, sum, arr.size(), dp);
  }
};

//{ Driver Code Starts.
int main()
{
  int sum = 30;
  vector<int> arr({3, 34, 4, 12, 5, 2});
  Solution ob;
  cout << ob.isSubsetSum(arr, sum) << endl;
  return 0;
}

// } Driver Code Ends