#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  int snakesAndLadders(vector<vector<int>> &board)
  {
    int rowMax = board.size();
    int colMax = board[0].size();

    int r = rowMax-1;
    int c = 0;
    bool isRowEven = (rowMax%2==0);
    queue<pair<int, int>> bfsQueue;
    bfsQueue.push(make_pair(rowMax-1, 0));

    int count = 0;
    while (bfsQueue.empty() == false)
    {
      count++;
      int size = bfsQueue.size();
      while (size > 0)
      {
        pair<int, int> data = bfsQueue.front();
        bfsQueue.pop();
        r = data.first;
        c = data.second;
        for(int i = 1; i < 6; ++i)
        {
          bool isEven = (r%2==0);
          int mul = 1;
          if(isRowEven == isEven)
          {
            mul = -1;
          }
          c = c+mul*1;
          if(c <= 0 && r <= 0)
          {
            return count;
          }
          if(c >= colMax)
          {
            r = r-1;
            c = colMax-1;
          }
          if(c < 0)
          {
            c = 0;
            r = r-1;
          }
          if(board[r][c] == -1)
          {
            bfsQueue.push(make_pair(r, c));
          }
          else if(r < board[r][c])
          {
            bfsQueue.push(make_pair(r, c));
          }

        }
      }
      
    }
    


  }
};

int main()
{
  vector<vector<int>> board{{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
  Solution sol;
  cout<<sol.snakesAndLadders(board);
  return 0;
}