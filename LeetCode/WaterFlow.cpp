#include <vector>
#include <iostream>

using namespace std;

class Solution
{
  vector<vector<int>> result;
  int rMax = 0;
  int cMax = 0;
  int neighbour[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  bool isValid(int r, int c)
  {
    if (r < 0 || c < 0 || r >= rMax || c >= cMax)
    {
      return false;
    }
    return true;
  }
  pair<int, int> pacificAtlantic(int r, int c, vector<vector<int>> &heights, vector<vector<pair<int, int>>> &dp)
  {
    pair<int, int> temp(-1, -1);
    if (r < 0 || c < 0 || r >= rMax || c >= cMax)
    {
      temp.first = r < 0 || c < 0;
      temp.second = r >= rMax || c >= cMax;
      return temp;
    }
    if (dp[r][c].first == -2 && dp[r][c].second == -2)
    {
      return make_pair(-2, -2);
    }
    if (dp[r][c].first >= 0 && dp[r][c].second >= 0)
    {
      return dp[r][c];
    }

    dp[r][c] = make_pair(-2, -2);

    for (int i = 0; i < 4; ++i)
    {
      int cR = r + neighbour[i][0];
      int cC = c + neighbour[i][1];
      if (isValid(cR, cC))
      {
        if (heights[r][c] > heights[cR][cC])
        {
          temp = pacificAtlantic(cR, cC, heights, dp);
        }
      }
      else
      {
        temp = pacificAtlantic(cR, cC, heights, dp);
      }
      if(temp.first == 1)
      {
        dp[r][c].first = 1;
      }
      if(temp.second == 1)
      {
        dp[r][c].second = 1;
      }
    }
    if(dp[r][c].first < 0)
    {
      dp[r][c].first = 0;
    }
    if(dp[r][c].second < 0)
    {
      dp[r][c].second = 0;
    }
    if(dp[r][c].first == 1 && dp[r][c].second == 1)
    {
      result.push_back({r, c});
    }
    return dp[r][c];
  }

public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
  {
    vector<vector<pair<int, int>>> dp(heights.size(), vector<pair<int, int>>(heights[0].size(), make_pair(-1, -1)));
    rMax = heights.size();
    cMax = heights[0].size();
    for(int i = 0; i < heights.size(); ++i)
    {
      for (int j = 0; j < heights[i].size(); j++)
      {
        if(dp[i][j].first == -1 && dp[i][j].second == -1)
        {
          pacificAtlantic(i, j, heights, dp);
        }
      }
    }
    return result;
  }
};


int main()
{
  Solution sol;
  vector<vector<int>> heights{{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
  vector<vector<int>> res = sol.pacificAtlantic(heights);
  return 0;
}