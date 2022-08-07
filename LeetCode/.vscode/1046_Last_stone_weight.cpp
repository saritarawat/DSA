#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cfloat>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int lastStoneWeight(vector<int> &stones)
  {
    if(stones.size() == 0)
    {
      return 0;
    }
    priority_queue<int> maxHeap;

    for (auto i : stones)
    {
      maxHeap.push(i);
    }

    int val = stones[0];
    while (maxHeap.size() > 1)
    {
      int x = maxHeap.top();
      int y = 0;
      maxHeap.pop();
      if(maxHeap.empty() == false)
      {
        y = maxHeap.top();
        maxHeap.pop();
      }
      val = abs(x-y);
      maxHeap.push(val);
    }
    return val;
  }
};

int main()
{
  Solution sol;
  vector<int> data({2,7,4,1,8,1});
  cout<<sol.lastStoneWeight(data)<<endl;
  return 0;
}