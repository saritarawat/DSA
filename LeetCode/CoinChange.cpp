//{ Driver Code Starts
#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
  long long int countUtil(int coins[], int len, int sum, vector<vector<long long int>>& dp)
  {
    if(sum == 0)
    {
      return 1;
    }
    if(len == 0)
    {
      return 0;
    }

    if(dp[len][sum] != -1)
    {
      return dp[len][sum];
    }

    if(coins[len-1] > sum)
    {
      return dp[len][sum] = countUtil(coins, len-1,sum, dp);
    }

    return (dp[len][sum] = countUtil(coins, len,sum-coins[len-1], dp)+countUtil(coins, len-1,sum, dp));
  }

public:
  long long int count(int coins[], int N, int sum)
  {
    // code here.
    vector<vector<long long int>> dp(N+1, vector<long long int>(sum+1, -1));
    return countUtil(coins, N, sum, dp);
  }
};

//{ Driver Code Starts.
int main()
{
  int sum = 10;
  const int N = 4;
  int coins[N] = {2, 5, 3, 6};
  Solution ob;
  cout << ob.count(coins, N, sum) << endl;
  return 0;
}

// } Driver Code Ends