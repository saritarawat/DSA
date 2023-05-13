//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
  int neighbours[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  using VertexData = tuple<int, int, int>;

  bool isValid(int r, int c, int n, int m)
  {
    if(r < 0 || r >= n || c < 0 || c >= m)
    {
      return false;
    }
    return true;
  }
  int shotestPathUtil(vector<vector<int>> &mat, int n, int m, int k)
  {
    // code here
    if (mat[0][0] == 1 && k <= 0)
    {
      return -1;
    }

    if (mat[0][0] == 1 && k > 0)
    {
      k--;
    }

    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
    queue<VertexData> bfsQueue;
    bfsQueue.push(make_tuple(0, 0, k));
    while (bfsQueue.empty() == false)
    {
      int size = bfsQueue.size();
      for(int i = 0; i < size; ++i)
      {
        VertexData vdata = bfsQueue.front();
        bfsQueue.pop();
        int r = get<0>(vdata);
        int c = get<1>(vdata);
        int lives = get<2>(vdata);
        for(int j = 0; j < 4; ++j)
        {
          if(isValid(r+neighbours[j][0], c+neighbours[j][1], n, m))
          {
            if(mat[r+neighbours[j][0]][c+neighbours[j][1]] == 0)
            {

            }
            else(lives > 0)
            {
              
            }
          }
        }
      }
    }
  }

public:
  int shotestPath(vector<vector<int>> mat, int n, int m, int k)
  {
    // code here
    return shotestPathUtil(mat, n, m, k);
  }
};

//{ Driver Code Starts.

int main()
{
  vector<vector<int>> mat{{0, 0, 0},
                          {0, 0, 1},
                          {0, 1, 0}};
  Solution ob;
  cout << ob.shotestPath(mat, 3, 3, 1);

  return 0;
}
// } Driver Code Ends