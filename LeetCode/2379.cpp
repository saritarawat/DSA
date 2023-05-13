#include "common.h"

class Solution
{
  int l = 0;
  int minimumRecolorsUtil(string& blocks, int size, int k, vector<vector<int>>& dp)
  {
    if(k == 0)
    {
      return 0;
    }
    if(size < k)
    {
      return -1;
    }
    if(dp[size][k] != -2)
    {
      return dp[size][k];
    }
    if(blocks[size-1] == 'B')
    {
      return dp[size][k] = minimumRecolorsUtil(blocks, size-1, k-1, dp);
    }

    int val1 = minimumRecolorsUtil(blocks, size-1, l, dp);
    int val2 = 1+minimumRecolorsUtil(blocks, size-1, k-1, dp);
    if(val1 == -1)
    {
      return dp[size][k] = val2;
    }
    else if(val2 == -1)
    {
      return dp[size][k] = val1;
    }
    return dp[size][k] = min(val1, val2);
  }
public:
  int minimumRecolors(string blocks, int k)
  {
    l = k;
    vector<vector<int>> dp(blocks.length()+1, vector<int>(k+1, -2));
    return minimumRecolorsUtil(blocks, blocks.length(), k, dp);
  }
};

int main()
{
  Solution sol;
  string str = "WBBWWBBWBW";
  cout<< sol.minimumRecolors(str, 7);
  return 0;
}