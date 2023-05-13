#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    vector<vector<string>> result;
    if(strs.size() == 0)
    {
      return result;
    }

    unordered_map<string, vector<string>> dataBase;
    

    for(int i = 0; i < strs.size(); ++i)
    {
      vector<int> charCount(26, 0);
      for (int j = 0; j < strs[i].length(); j++)
      {
        charCount[strs[i][j]-'a']++;
      }
      string temp;
      for (int j = 0; j < charCount.size(); j++)
      {
        if(charCount[j] > 0)
        {
          temp+=to_string(charCount[j]);
          temp.push_back('a'+j);
        }
      }
      dataBase[temp].push_back(strs[i]);
    }

    for(auto itr = dataBase.begin(); itr!=dataBase.end(); ++itr)
    {
      result.emplace_back(move(itr->second));
    }
    return result;
  }
};

int main()
{
  Solution sol;
  vector<string> strs{"eat","tea","tan","ate","nat","bat"};
  sol.groupAnagrams(strs);
  return 0;
}