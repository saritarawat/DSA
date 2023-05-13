#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string>

using namespace std;

class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    vector<int> result;
    unordered_map<int, int> numCountMap;
    map<int, unordered_set<int>> countNumList;

    for(auto& i : nums)
    {
      if(numCountMap[i] > 0)
      {
        countNumList[numCountMap[i]].erase(i);
        numCountMap[i]++;
      }
      countNumList[numCountMap[i]].insert(i);
    }


    for(auto itr = countNumList.rbegin(); itr != countNumList.rend(); ++itr)
    {
      if(k == 0)
      {
        break;
      }
      k--;
      result.push_back()
    }
  }
};