#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  int neigh[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int rMax = 0;
  int cMax = 0;

private:
  int maxAreaOfIslandUtil(vector<vector<int>> &grid, int r, int c, vector<vector<bool>> &visited)
  {
    if (visited[r][c])
    {
      return 0;
    }

    visited[r][c] = true;
    int count = 1;
    for(int i = 0; i < 4; ++i)
    {
      int j = r+neigh[i][0];
      int k = c+neigh[i][1];

      if(j >= 0 && j < rMax && k >= 0 && k < cMax && grid[j][k] == 1)
      {
        count+=maxAreaOfIslandUtil(grid, j, k, visited);
      }
    }
    return count;
  }

public:
  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    int count = 0;
    if(grid.size() == 0)
    {
      return 0;
    }
    rMax = grid.size();
    cMax = grid[0].size();
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    for(int i = 0; i < grid.size(); ++i)
    {
      for (int j = 0; j < grid[i].size(); j++)
      {
        /* code */
        if(visited[i][j] == false && grid[i][j] == 1)
        {
          count=max(count, maxAreaOfIslandUtil(grid, i, j, visited));
        }
      }
    }
    return count;
  }
};