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
  bool backspaceCompare(string s, string t)
  {
    int id1 = 0;
    for(int i = 0; i < s.length(); ++i) 
    {
      if(s[i] != '#')
      {
        s[id1++] = s[i];
      }
      else
      {
        if(id1 > 0)
        {
          id1--;
        }
      }
    }

    int id2 = 0;
    for(int i = 0; i < t.length(); ++i) 
    {
      if(t[i] != '#')
      {
        t[id2++] = t[i];
      }
      else
      {
        if(id2 > 0)
        {
          id2--;
        }
      }
    }

    if(id1 == id2)
    { 
      int i = 0;
      while(i <id1)
      {
        if(s[i] != t[i])
        {
          return false;
        }
        i++;
      }
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  cout << Solution().backspaceCompare("a#c", "d") << endl;
  return 0;
}