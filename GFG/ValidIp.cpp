#include "common.h"
#include <sstream>

// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution
{
public:
  int isValid(string s)
  {
    // code here
    stringstream ss(s);
    string tempStr;
    int count = 0;
    while (getline(ss, tempStr, '.'))
    {
      count++;
      int len = tempStr.length();
      if (len < 1 || len > 3)
      {
        return 0;
      }

      if (len == 1 && tempStr[0] - '0' >= 0 && tempStr[0] - '0' <= 9)
      {
        continue;
      }
      if (tempStr[0] - '0' == 0)
      {
        return 0;
      }

      int mul = 10;
      int num = 0;
      int i = 0;
      while (i < len)
      {
        if ((tempStr[i] - '0' >= 0 && tempStr[i] - '0' <= 9) == false)
        {
          return 0;
        }
        num = num * 10 + (tempStr[i] - '0');
        if (num > 255)
        {
          return 0;
        }
        i++;
      }
    }
    if (count != 4 || s[s.length()-1] == '.')
    {
      return 0;
    }
    return 1;
  }
};

//{ Driver Code Starts.

int main()
{
  string s("0.0.0.0a");
  Solution ob;
  cout << ob.isValid(s) << endl;
  return 0;
}
// } Driver Code Ends