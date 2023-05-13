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
  int lengthOfLIS(vector<int> &nums)
  {
    size_t len = nums.size();
    if(len == 0 || len == 1)
    {
      return len;
    }
    int i =0;
    int j = 1;
    vector<int> maxVal(nums.size(), 1);
    int maxNum = 1;
    while(j < len)
    {
      if(nums[i] < nums[j])
      {
        maxVal[j] = max(maxVal[j], maxVal[i]+1);
        maxNum = max(maxNum, maxVal[j]);
      }
      i++;
      if(i == j)
      {
        i =0;
        j++;
      }
    }
    return maxNum;
  }
};

int main()
{
  Solution sol;
  vector<int> nums{0,1,0,3,2,3};
  cout << "Ans : " << sol.lengthOfLIS(nums) << endl;
  return 0;
}