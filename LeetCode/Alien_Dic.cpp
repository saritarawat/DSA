// { Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
  unordered_map<char, int> charIndexMap;
  unordered_map<int, char> indexCharMap;
  void BuildGraph(string dic[], vector<vector<int>> &graph, int N)
  {
    int id = 0;
    for (int i = 0; i < N - 1; ++i)
    {
      int j = 0;
      int len = min(dic[i].length(), dic[i + 1].length());
      while (j < len)
      {
        if (dic[i][j] != dic[i + 1][j])
        {
          if (charIndexMap.find(dic[i][j]) == charIndexMap.end())
          {
            charIndexMap[dic[i][j]] = id;
            indexCharMap[id] = dic[i][j];
            id++;
          }
          if (charIndexMap.find(dic[i + 1][j]) == charIndexMap.end())
          {
            charIndexMap[dic[i + 1][j]] = id;
            indexCharMap[id] = dic[i + 1][j];
            id++;
          }
          int v1 = charIndexMap[dic[i][j]];
          int v2 = charIndexMap[dic[i + 1][j]];
          graph[v1].push_back(v2);
          break;
        }
        j++;
      }
    }
  }

  void TopologicalSort(int id, vector<vector<int>>& graph, vector<bool>& visited, string& result)
  {
    if(visited[id])
    {
      return;
    }
    visited[id] = true;

    for(int i = 0; i < graph[id].size(); ++i)
    {
      TopologicalSort(graph[id][i], graph, visited, result);
    }
    result.push_back(indexCharMap[id]);
  }

public:
  string findOrder(string dict[], int N, int K)
  {
    vector<vector<int>> graph(K);
    vector<bool> visited(K, false);
    BuildGraph(dict, graph, N);
    string result;
    for(int i = 0; i < K; ++i)
    {
      if(visited[i] == false)
      {
        TopologicalSort(i, graph, visited, result);
      }
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

// { Driver Code Starts.
string order;
bool f(string a, string b)
{
  int p1 = 0;
  int p2 = 0;
  for (int i = 0; i < min(a.size(), b.size()) && p1 == p2; i++)
  {
    p1 = order.find(a[i]);
    p2 = order.find(b[i]);
    //	cout<<p1<<" "<<p2<<endl;
  }

  if (p1 == p2 && a.size() != b.size())
    return a.size() < b.size();

  return p1 < p2;
}

// Driver program to test above functions
int main()
{
  Solution obj;
  string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
  //string dict[] = {"caa","aaa","aab"};
  string ans = obj.findOrder(dict, 5, 4);
  return 0;
}
// } Driver Code Ends