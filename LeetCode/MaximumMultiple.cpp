// { Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
  unordered_map<char, vector<int>> colorCityMap;

public:
  bool isValisPath(int N, char ch, string &col, unordered_set<char> &colorSet, vector<vector<int>> &graph)
  {
    unordered_set<char> colorSet1;
    vector<int> &cityList = colorCityMap[ch];

    for (int i = 0; i < cityList.size(); ++i)
    {
      vector<bool> visited(N, false);
      queue<int> bfsQueue;
      bfsQueue.push(cityList[i]);
      colorSet1.insert(col[cityList[i]]);
      visited[cityList[i]] = true;

      while (bfsQueue.empty() == false && colorSet1.size() != 3)
      {
        int node = bfsQueue.front();
        bfsQueue.pop();
        for (int j = 0; j < graph[node].size(); ++j)
        {
          char nColor = col[graph[node][j]];
          if (visited[graph[node][j]] == false && colorSet.find(nColor) != colorSet.end())
          {
            colorSet1.insert(nColor);
            bfsQueue.push(graph[node][j]);
            visited[graph[node][j]] = true;
            if (colorSet1.size() == 3)
            {
              return true;
            }
          }
        }
      }
    }
    return false;
  }

  vector<string> solve(int N, int M, int Q, string col, vector<vector<int>> &Edge, vector<string> &query)
  {
    // code here
    vector<vector<int>> graph(N);
    vector<string> res;
    for (int i = 0; i < Edge.size(); ++i)
    {
      if (Edge[i].empty() == false)
      {
        graph[Edge[i][0]].push_back(Edge[i][1]);
        graph[Edge[i][1]].push_back(Edge[i][0]);
      }
    }

    for (int i = 0; i < col.size(); ++i)
    {
      colorCityMap[col[i]].push_back(i);
    }

    for (int i = 0; i < query.size(); ++i)
    {
      unordered_set<char> colorSet;
      for (int j = 0; j < 3; j++)
      {
        colorSet.insert(query[i][j]);
      }
      bool result = isValisPath(N, query[i][0], col, colorSet, graph);
      res.push_back(result ? "YES" : "NO");
    }
    return res;
  }
};

// { Driver Code Starts.

int main()
{
  int N = 6;
  int M = 7;
  int Q = 3;
  string col("abdebc");
  vector<vector<int>> Edge{{0, 1}, {0, 2}, {1, 3}, {1, 4}, {1, 2}, {2, 4}, {4, 5}};
  vector<string> query{"abc", "aec", "azc"};

  Solution ob;
  vector<string> annswer = ob.solve(N, M, Q, col, Edge, query);

  for (auto it : annswer)
    cout << it << "\n";
  return 0;
}
// } Driver Code Ends