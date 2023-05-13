//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
  int cutRodUtil(int price[], int len, int targetLen, vector<vector<int>>& dp)
  {
    if(len == 0 || targetLen == 0)
    {
      return 0;
    }

    if(dp[len][targetLen] != -1)
    {
      return dp[len][targetLen];
    }
    if(len > targetLen)
    {
      return dp[len][targetLen] = cutRodUtil(price, len-1, targetLen, dp);
    }

    return dp[len][targetLen] = max(price[len-1]+cutRodUtil(price, len, targetLen-len, dp), cutRodUtil(price, len-1, targetLen, dp));
  }

public:
  int cutRod(int price[], int n)
  {
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return cutRodUtil(price, n, n, dp);
  }
};

//{ Driver Code Starts.

int main()
{
  const int n = 8;
  int a[n] = {3, 5, 8, 9, 10, 17, 17, 20};

  Solution ob;

  cout << ob.cutRod(a, n) << endl;
  return 0;
}
// } Driver Code Ends