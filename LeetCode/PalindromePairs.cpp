#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{

  int getIndex(int id, vector<string> &words)
  {
    if(words[id] == "")
    {
      return id+1;
    }
    int start = id+1;
    int end = words.size()-1;
    int result = -1;
    while (start <= end)
    {
      int mid = start + (end-start)/2;
      int len1 = words[id].length()-1;
      int len2 = words[mid].length()-1;
      if(words[id][len1] == words[mid][0] ||  (len2 > 0 && words[id][len1] == words[mid][1]) || (len1 > 0 && words[id][len1-1] == words[mid][0]))
      {
        result = mid;
        end = mid-1;
      }
      else if(words[id][words[id].length()-1] < words[mid][0])
      {
        end = mid-1;
      }
      else
      {
        start = mid+1;
      }
    }
    return result;
  }

  int isPalindromes(string& str1, string& str2)
  {
    string str = str1+str2;
    string strstr = str2+str1;
    int len = str.length();
    int i = 0;
    int j = len-1;
    int i1 = 0;
    int j1 = len-1;
    while (i < j && i1 < j1)
    {
      if(str[i] != str[j] && strstr[i1] != strstr[j1])
      {
        return -1;
      }

      if(str[i] == str[j])
      {
        i++;
        j--;
      }
      if(strstr[i1] == strstr[j1])
      {
        i1++;
        j1--;
      }
    }
    if(i >= j && i1 >= j1)
    {
      return 3;
    }
    else if(i1 >= j1)
    {
      return 2;
    }
    return 1;
  }

public:
  vector<vector<int>> palindromePairs(vector<string> &words)
  {
    unordered_map<string, int> stringIndex;
    for(int i = 0; i < words.size(); ++i)
    {
      stringIndex[words[i]] = i;
    }

    sort(words.begin(), words.end());
    vector<vector<int>> result;

    for(int i = 0; i < words.size(); ++i)
    {
      int id = getIndex(i, words);
      if(id == -1)
      {
        continue;
      }
      for (int j = id; j < words.size(); j++)
      {
        int val = isPalindromes(words[i], words[j]);
        if(val == 1)
        {
          result.push_back({stringIndex[words[i]], stringIndex[words[j]]});
        }
        else if(val == 2)
        {
          result.push_back({stringIndex[words[j]], stringIndex[words[i]]});
        }
        else if(val == 3)
        {
          result.push_back({stringIndex[words[i]], stringIndex[words[j]]});
          result.push_back({stringIndex[words[j]], stringIndex[words[i]]});
        }
      }
    }
    return result;
  }
};

int main()
{
  vector<string> words{"ab","ba","abc","cba"};
  Solution sol;
  vector<vector<int>> result = sol.palindromePairs(words);
  return 0;
}