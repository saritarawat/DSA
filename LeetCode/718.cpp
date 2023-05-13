#include "common.h"

class Solution
{
  int findLengthUtil(vector<int> &nums1, vector<int> &nums2, int len1, int len2, int curmax, int& maxVal, vector<vector<int>>& dp)
  {
    if(len1 == 0 || len2 == 0)
    {
      return 0;
    }
    
    if(dp[len1][len2] != -1)
    {
      return dp[len1][len2];
    }

    if(nums1[len1-1] == nums2[len2-1])
    {
      maxVal = max(maxVal, 1+curmax);
      int val = findLengthUtil(nums1, nums2, len1-1, len2-1, curmax+1, maxVal, dp);
      dp[len1][len2] = maxVal;
    }
    findLengthUtil(nums1, nums2, len1-1, len2, 0, maxVal, dp);
    findLengthUtil(nums1, nums2, len1, len2-1, 0, maxVal, dp);
    dp[len1][len2] = maxVal;
    return;
  }
public:
  int findLength(vector<int> &nums1, vector<int> &nums2)
  {
    int maxVal = 0;
    vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, -1));
    findLengthUtil(nums1, nums2, nums1.size(), nums2.size(), 0, maxVal, dp);
    return maxVal;
  }
};



int main()
{
  vector<int> nums1{1,2,3,2,1};
  vector<int> nums2{3,2,1,4,7};
  Solution sol;
  cout<<sol.findLength(nums1, nums2);
  return 0;
}