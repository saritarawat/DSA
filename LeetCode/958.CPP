#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;


class Solution
{
public:
  vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
  {
    vector<int> result;
    int sum = 0;
    unordered_set<int> evenIndex;
    for(int i = 0; i < nums.size(); ++i)
    {
      if(nums[i]%2 == 0)
      {
        evenIndex.insert(i);
        sum+=nums[i];
      }
    }

    for(int i = 0; i < queries.size(); ++i)
    {
      int val = queries[i][0];
      int index = queries[i][1];
      int tempVal = val+nums[index];

      if(abs(tempVal)%2 == 0)
      {
        if(evenIndex.find(index) != evenIndex.end())
        {
          sum+=val;
        }
        else
        {
          evenIndex.insert(index);
          sum+=tempVal;
        }
      }
      else
      {
        if(evenIndex.find(index) != evenIndex.end())
        {
          sum-=nums[index];
          evenIndex.erase(index);
        }
      }
      nums[index] = tempVal;
      result.push_back(sum);
    }
    return result;
  }
};


int main()
{
  char a = 'a';
  a = a+1;
  cout<<"a : "<<a;

  vector<int> nums{1};
  vector<vector<int>> queries{{4,0}};
  Solution sol;
  vector<int> result = sol.sumEvenAfterQueries(nums, queries);

  for(auto& val : result)
  {
    cout<< val << ", ";
  }
  return 0;
}