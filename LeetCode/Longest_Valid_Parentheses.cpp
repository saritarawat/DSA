//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  int maxLength(string S)
  {
    stack<int> closesBracketIndexes;
    int result = 0;
    for(int i = 0; i < S.length(); ++i)
    {
      if(S[i] == '(')
      {
        closesBracketIndexes.push(i);
      }
      else
      {
        if(closesBracketIndexes.empty())
        {
          closesBracketIndexes.push(i);
        }
        else
        {
          int topIndex = closesBracketIndexes.top();
          if(S[topIndex] == '(')
          {
            closesBracketIndexes.pop();
            int id = closesBracketIndexes.empty()?-1:closesBracketIndexes.top();
            result = max(result, i-id);
          }
          else
          {
            closesBracketIndexes.push(i);
          }
        }
      }
    }
    return result;
  }
};

//{ Driver Code Starts.

int main()
{
  Solution ob;
  string S(")())(())");
  cout << ob.maxLength(S) << "\n";
  return 0;
}
// } Driver Code Ends