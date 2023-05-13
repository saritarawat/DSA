#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{

private:
  bool CycleDetected(int id, int numCourses, vector<vector<int>> &prerequisites, vector<int> &visited, vector<int>& result)
  {
    if(id == numCourses)
    {
      return false;
    }

    if (visited[id] == 2)
    {
      return false;
    }
    if (visited[id] == 1)
    {
      return true;
    }

    visited[id] = 1;
    for (int i = 0; i < prerequisites[id].size(); ++i)
    {
      if (CycleDetected(prerequisites[id][i], numCourses, prerequisites, visited, result))
      {
        return true;
      }
    }
    visited[id] = 2;
    result.push_back(id);
    return false;
  }

public:
  vector<int> canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<vector<int>> prerequisite(numCourses, vector<int>());
    vector<int> result;
    for (int i = 0; i < prerequisites.size(); ++i)
    {
      cout << prerequisites[i][0] << endl;
      cout << prerequisites[i][1] << endl;
      prerequisite[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }

    vector<int> visited(numCourses, 0);
    for (int i = 0; i < prerequisite.size(); ++i)
    {
      if (visited[i] == 0)
      {
        if (CycleDetected(i, numCourses, prerequisite, visited, result))
        {
          result.clear();
          return result;
        }
      }
    }
    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> adj;
  adj.push_back({1, 0});
  adj.push_back({2, 0});
  adj.push_back({3, 1});
  adj.push_back({3, 2});
  sol.canFinish(4, adj);
  return 0;
}