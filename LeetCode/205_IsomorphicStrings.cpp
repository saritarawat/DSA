#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    if(s.size() != t.size())
    {
      return false;
    }

    unordered_map<char, char> charMap;

    for(int i = 0; i < s.size(); ++i)
    {
      if(charMap.find(t[i]) == charMap.end())
      {
        for(auto it:charMap){
                    if(it.second==t[i])return false;
                }
        charMap[s[i]] = t[i];
      }
      else
      {
        if(charMap[s[i]] != t[i])
        {
          return false;
        }
      }
    }
    return true;
  }
};