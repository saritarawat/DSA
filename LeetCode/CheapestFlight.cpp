
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
  unordered_map<int, vector<pair<int, int>>> adjList;

public:
  int findCheapestPrice(int s, vector<vector<int>> &flights, int src, int dst, int k)
  {
    int n = flights.size();
    if (n == 0)
    {
      return 0;
    }
    int result = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
      adjList[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
    }
    queue<pair<int, int>> bfs;
    unordered_set<int, cost> visited;
    bfs.push(make_pair(src, 0));
    int stops = 0;

    while (stops <= k && bfs.empty() == false)
    {
      int size = bfs.size();
      while (size > 0)
      {
        pair<int, int> data = bfs.front();
        int u = data.first;
        int cost = data.second;
        if (visited.find(u) != visited.end())
        {
          continue;
        }
        // process all neighbours
        vector<pair<int, int>> &list = adjList[u];
        for (auto itr : list)
        {
          if (visited.find(itr.first) != visited.end())
          {
            continue;
          }
        }
      }
    }

    maxStops = k;
    mDst = dst;
    priority_queue<triple, vector<triple>, greater<triple>> minHeap;
    unordered_set<int> visited;

    vector<bool> vis(s, false);
    findCheapestPriceUtil(src, vis, -1, 0);
    return resultUpdated ? result : -1;
    minHeap.push(make_tuple(0, 0, src));

    while (minHeap.empty() == false)
    {
      triple data = minHeap.top();
      minHeap.pop();
      int cost = get<0>(data);
      int stops = get<1>(data);
      int u = get<2>(data);

      if (u == dst)
      {
        return cost;
      }

      if (visited.find(u) != visited.end())
      {
        continue;
      }
      visited.insert(u);
      vector<pair<int, int>> &list = adjList[u];
      for (auto &item : list)
      {
        if (visited.find(item.second) == visited.end())
        {
          if (item.second == dst)
          {
            if (stops <= k)
            {
              minHeap.push(make_tuple(cost + item.first, stops + 1, item.second));
            }
          }
          else
          {
            if (stops < k)
            {
              minHeap.push(make_tuple(cost + item.first, stops + 1, item.second));
            }
          }
        }
      }
    }
    return -1;
  }
};