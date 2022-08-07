#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
bool isBadVersion(int version)
{
  return true;
}
class Solution
{
public:
  int firstBadVersion(int n)
  {
    int l = 1;
    int r = n;
    int badVersion = -1;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;

      bool result = isBadVersion(mid);
      if (result)
      {
        badVersion = mid;
        r = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }
    return badVersion;
  }
};