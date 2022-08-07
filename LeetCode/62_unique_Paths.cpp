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
  int uniquePaths(int m, int n)
  {
    if(m == 0 || n == 0)
    {
      return 0;
    }
    vector<vector<int>> dp(m, vector<int>(n, -1));
    vector<vector<bool>>visitedNodes(m, vector<bool>(n, false));
    return uniquePathsUtil(0, 0, m ,n, dp, visitedNodes);
  }

private:
  int uniquePathsUtil(int r, int c, int m, int n, vector<vector<int>>& dp, vector<vector<bool>>& visitedNodes)
  {
    if(r < 0 || r >= m || c < 0 || c >= n)
    {
      return 0;
    }

    if(visitedNodes[r][c])
    {
      return 0;
    }

    if(r == m-1 && c == n-1)
    {
      return 1;
    }

    visitedNodes[r][c] = true;

    if(dp[r][c] != -1)
    {
      return dp[r][c];
    }

    // right neighbour
    int count = uniquePathsUtil(r, c+1, m, n, dp, visitedNodes);
    count+=uniquePathsUtil(r+1, c, m, n, dp, visitedNodes);
    dp[r][c] = count;
    visitedNodes[r][c] = false;

    return dp[r][c];
  }
};

int main()
{
  cout << Solution().uniquePaths(3, 7) << endl;
  return 0;
}