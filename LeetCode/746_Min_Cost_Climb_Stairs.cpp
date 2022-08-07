#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cfloat>
#include <stack>
using namespace std;

class Solution
{

public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    if(cost.size() == 0)
    {
      return 0;
    }

    if(cost.size() == 1)
    {
      return cost[0];
    }

    int last[2] = {cost[0], cost[1]};
    for(int i = 2; i < cost.size(); ++i)
    {
      int sum = min(last[0], last[1])+cost[i];
      last[0] = last[1];
      last[1] = sum;
    }
    return min(last[0], last[1]);
  }
};

int main()
{
  vector<int> data({110, 15, 20});
  cout << Solution().minCostClimbingStairs(data) << endl;
  return 0;
}