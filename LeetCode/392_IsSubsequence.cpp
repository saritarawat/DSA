#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
      int sLen = s.length();    
      int tLen = t.length();
      
      int  i = 0;
      int k = 0;
      
      while(i < sLen && sLen-i <= tLen-k)
      {
        if(s[i] == t[k])
        {
          i++;
        }
        k++;
      }
      
      return (i == sLen);
    }
};