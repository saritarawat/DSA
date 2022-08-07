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
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
  {
    if (image.size() == 0)
    {
      vector<vector<int>> temp;
      return temp;
    }
    vector<vector<int>> result;
    result = image;

    floodFillUtil(image, result, sr, sc, color);
    return result;
  }

private:

  int neighbours[4][2] = {{-1,0}, {1,0}, {0, -1}, {0, 1}};

  void floodFillUtil(vector<vector<int>> &image, vector<vector<int>> &result, int sr, int sc, int color)
  {
    int startColor = image[sr][sc];
    queue<pair<int, int>> levelOrderData;
    vector<vector<bool>> visitedNodes(image.size(), vector<bool>(image[0].size(), false));

    if(image[sr][sc] == color)
    {
      return;
    }
    levelOrderData.push(make_pair(sr, sc));
    visitedNodes[sr][sc] = true;

    while (levelOrderData.empty() == false)
    {
      pair<int, int> temp = levelOrderData.front();
      levelOrderData.pop();
      result[temp.first][temp.second] = color;

      for(int i = 0; i < 4; ++i)
      {
        int x = temp.first+neighbours[i][0];
        int y = temp.second+neighbours[i][1];

        if(x >= 0 &&  x < image.size() && y >= 0 && y < image[0].size() && visitedNodes[x][y] == false && image[x][y] == startColor)
        {
          levelOrderData.push(make_pair(x, y));
          visitedNodes[x][y] = true;
        }
      }
    }
  }
};

int main()
{
  vector<vector<int>> image(2, vector<int>(3, 0));

  Solution sol;
  sol.floodFill(image, 1,0,2);
}