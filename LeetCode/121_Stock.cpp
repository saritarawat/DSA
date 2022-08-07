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
  int maxProfit(vector<int> &prices)
  {
    if(prices.size() == 0|| prices.size() == 1)
    {
      return 0;
    }

    int maxVal = 0;
    int minVal = prices[0];

    for(auto& i : prices)
    {
      minVal = min(minVal, i);
      maxVal = max(maxVal, i-minVal);
    }
    return maxVal;
  }
};


int main()
{
  vector<int> prices{7,6,4,3,1};

  Solution sol;
  cout<< "profit :" << sol.maxProfit(prices)<< endl;
  return 0;
}