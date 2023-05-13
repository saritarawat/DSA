//{ Driver Code Starts
#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
class Solution
{
  int minCoinsUtil(int coins[], int len, int sum, vector<vector<int>> &dp)
  {
    // Your code goes here
    if (sum == 0)
    {
      return 0;
    }
    if (len == 0)
    {
      return INT_MAX;
    }
    if(dp[len][sum] != -1)
    {
      return dp[len][sum];
    }
    if (coins[len - 1] > sum)
    {
      int val = minCoinsUtil(coins, len - 1, sum, dp);
      return dp[len][sum] = val;
    }
    int val1 = minCoinsUtil(coins, len, sum - coins[len - 1], dp);
    int val2 = minCoinsUtil(coins, len - 1, sum, dp);
    if (val1 != INT_MAX)
    {
      val1++;
    }
    return dp[len][sum] = min(val1, val2);
  }

public:
  int minCoins(int coins[], int n, int sum)
  {
    // Your code goes here
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    int val = minCoinsUtil(coins, n, sum, dp);
    if (val == INT_MAX)
    {
      return -1;
    }
    return val;
  }
};

//{ Driver Code Starts.
int main()
{
  int sum = 11;
  const int N = 4;
  int coins[N] = {9, 6, 5, 1};
  Solution ob;
  cout << ob.minCoins(coins, N, sum) << endl;

  return 0;
}

// } Driver Code Ends