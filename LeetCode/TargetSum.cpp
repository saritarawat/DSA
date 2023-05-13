#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  int findTargetSumWaysUtil(vector<int> &nums, int target, int val, int len, vector<vector<int>>& dp)
  {
    if(len == 0)
    {
      if(val == target)
      {
        return 1;
      }
      return 0;
    }
    // if(dp[len][val] != -1) 
    // {
    //   return dp[len][val];
    // }
    return findTargetSumWaysUtil(nums, target, val+nums[len-1], len-1, dp)+findTargetSumWaysUtil(nums, target, val-nums[len-1], len-1, dp);
  }
public:
  int findTargetSumWays(vector<int> &nums, int target)
  {
    vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, -1));
    return findTargetSumWaysUtil(nums, target, 0, nums.size(), dp);
  }
};

int main()
{
  vector<int> arr{1,1,1,1,1};
  Solution ob;
  cout << ob.findTargetSumWays(arr, 3) << "\n";
  return 0;
}