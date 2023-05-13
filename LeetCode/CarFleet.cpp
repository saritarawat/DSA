#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  using iPair = pair<int, int>;
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed)
  {
    int n = position.size();
    if(n == 0 || n == 1 )
    {
      return n;
    }
    vector<iPair> carInfo;
    for(int i = 0; i < n; ++i)
    {
      carInfo.push_back(make_pair(position[i], speed[i]));
    }

    sort(carInfo.begin(), carInfo.end());

    int count = 0;
    for(int i = n-1; i >= 0; )
    {
      int j = i-1;
      float ti = (target-carInfo[i].first)/(float)carInfo[i].second;
      float tj = 0;
      if(j >= 0)
      {
        tj  = (target-carInfo[j].first)/(float)carInfo[j].second;
      }

      while (j >= 0 && tj <= ti)
      {
        j--;
        tj  = ((float)target-carInfo[j].first)/(float)carInfo[j].second;
      }
      count++;
      i = j;
    }
    return count;
    }
};

int main()
{
  int target = 10;
  vector<int> pos{6,8};
  vector<int> speed{3,2};
  cout<<Solution().carFleet(target, pos, speed);
  return 0;
}