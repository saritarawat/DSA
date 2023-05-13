//{ Driver Code Starts
// Initial template for C++

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
  int n = 0;
  int m = 0;
  int neighboors[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  bool isValid(int r, int c)
  {
    if (r < 0 || r >= n || c < 0 || c >= m)
    {
      return false;
    }
    return true;
  }

  int findOccurrenceUtil(vector<vector<char>> &mat, int r, int c, string target, int index, vector<vector<vector<int>>> &visited)
  {
    if(isValid(r, c) == false || mat[r][c] != target[index])
    {
      return 0;
    }

    if (index+1 == target.length())
    {
      return 1;
    }

    if (visited[r][c][index] != -1)
    {
      return visited[r][c][index];
    }
    visited[r][c][index] = 0;
    int count = 0;
    for (int i = 0; i < 4; ++i)
    {
      int cR = r + neighboors[i][0];
      int cC = c + neighboors[i][1];
      count += findOccurrenceUtil(mat, cR, cC, target, index + 1, visited);
    }
    visited[r][c][index] = count;
    return visited[r][c][index];
  }

public:
  int findOccurrence(vector<vector<char>> &mat, string target)
  {
    if (mat.size() == 0)
    {
      return 0;
    }
    int count = 0;
    vector<vector<vector<int>>> visited(mat.size(), vector<vector<int>>(mat[0].size(), vector<int>(target.length() + 1, -1)));
    n = mat.size();
    m = mat[0].size();
    for (int i = 0; i < mat.size(); ++i)
    {
      for (int j = 0; j < mat[i].size(); ++j)
      {
        int ret = findOccurrenceUtil(mat, i, j, target, 0, visited);
        if (ret > 0)
        {
          count += ret;
        }
      }
    }
    return count;
  }
};

//{ Driver Code Starts.

int main()
{
  vector<vector<char>> mat{{'S', 'N', 'B', 'S', 'N'},
                           {'B', 'A', 'K', 'E', 'A'},
                           {'B', 'K', 'B', 'B', 'K'},
                           {'S', 'E', 'B', 'S', 'E'}};
  string target("SNAKES");
  Solution obj;
  cout << obj.findOccurrence(mat, target) << endl;
}

// } Driver Code Ends