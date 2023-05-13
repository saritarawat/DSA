#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
  int rMax = 0;
  int cMax = 0;
  int neigh[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  bool isValidNeighbour(int r, int c)
  {
    if(r < 0 || r >= rMax || c < 0 || c >= cMax)
    {
      return false;
    }
    return true;
  }

  void BFSUtil(queue<pair<int, int>>& bfsQueue, vector<vector<pair<bool, bool>>>& visited)
  {
    while (bfsQueue.empty() == false)
    {
      pair<int, int> grid = bfsQueue.front();
      int r = grid.first;
      int c = grid.second;
      for(int i = 0; i < 4; ++i)
      {
        int j = r+neigh[i][0];
        int k = r+neigh[i][1];
        if(isValidNeighbour(j, k) && )
      }
    }
    
  }
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
  {
    vector<vector<int>> result;
    if(heights.size() == 0)
    {
      return result;
    }
    rMax = heights.size();
    cMax = heights[0].size();
    vector<vector<pair<bool, bool>>> visited(rMax, vector<pair<bool, bool>>(cMax, make_pair(false, false)));
    
    queue<pair<int, int>> bfsQueue;

    for(int i = 0; i < cMax; ++i)
    {
      visited[0][i].second = true;
      bfsQueue.push(make_pair(0, i));
    }
    for(int i = 1; i < rMax; ++i)
    {
      visited[i][0].second = true;
      bfsQueue.push(make_pair(i, 0));
    }
    for(int i = 0; i < cMax; ++i)
    {
      visited[rMax-1][i].second = true;
      if(i != 0)
      {
        bfsQueue.push(make_pair(rMax-1, i));
      }
    }
    for(int i = 0; i < rMax-1; ++i)
    {
      visited[i][cMax-1].first = true;
      if(i != 0)
      {
        bfsQueue.push(make_pair(i, cMax-1));
      }
    }
  }
};

int main()
{

  return 0;
}