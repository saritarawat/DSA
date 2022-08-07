#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cfloat>
#include <stack>
using namespace std;

class Solution
{

public:
  int climbStairs(int n)
  {
    if(n == 0 || n == 1)
    {
      return n;
    }
    vector<int> dp(n+1, -1);
    return climbStairsUtil(n, dp);
  }

private:
  int climbStairsUtil(int n, vector<int>& dp)
  {
    if (n == 0 || n == 1)
    {
      return 1;
    }
    if(dp[n] != -1)
    {
      return dp[n];
    }

    dp[n] = climbStairsUtil(n - 1, dp) + climbStairsUtil(n - 2, dp); 
    return dp[n];
  }
};

int main()
{
  cout << Solution().climbStairs(3) << endl;
  return 0;
}