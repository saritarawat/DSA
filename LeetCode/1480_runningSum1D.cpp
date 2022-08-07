#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> runningSum(vector<int> &nums)
  {
    vector<int> result;
    int total = 0;
    for(auto i : nums)
    {
      total+=i;
      result.push_back(total);
    }
    return result;
  }
};