#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cfloat>
using namespace std;

class Solution
{
public:
  int numIslands(vector<vector<char>> &grid)
  {
    if (grid.size() == 0)
    {
      return 0;
    }

    int count = 0;

    vector<vector<bool>> visitesNodes(grid.size(), vector<bool>(grid[0].size(), false));

    for (int i = 0; i < grid.size(); ++i)
    {
      for (int j = 0; j < grid[i].size(); j++)
      {
        if (visitesNodes[i][j] == false && grid[i][j] == '1')
        {
          count++;
          numIslandsUtil(i, j, grid, visitesNodes);
        }
      }
    }
    return count;
  }

private:
  int neighbours[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  void numIslandsUtil(int r, int c, vector<vector<char>> &grid, vector<vector<bool>> &visitesNodes)
  {
    if (visitesNodes[r][c])
    {
      return;
    }

    visitesNodes[r][c] = true;

    for (int i = 0; i < 4; ++i)
    {
      int x = r + neighbours[i][0];
      int y = c + neighbours[i][1];

      if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1')
      {
        numIslandsUtil(x, y, grid, visitesNodes);
      }
    }
  }
};

int main()
{
  vector<vector<char>> grid;
  grid.push_back({'1','1','0','0','0'});
  grid.push_back({'1','1','0','0','0'});
  grid.push_back({'0','0','1','0','0'});
  grid.push_back({'0','0','0','1','1'});

  Solution sol;
  cout<<"Count: "<<sol.numIslands(grid)<<endl;
  return 0;
}