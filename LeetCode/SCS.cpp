//{ Driver Code Starts
// Initial template for C++

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
  pair<int, string> shortestCommonSupersequenceUtil(string& X, string& Y, int m, int n, vector<vector<pair<int, string>>>& dp)
  {
    // code here
    if(m == 0 && n == 0)
    {
      return make_pair(0, "");
    }
    if(m == 0)
    {
      string str = Y.substr(0, n);
      //reverse(str.begin(), str.end());
      return make_pair(n, str);
    }
    if(n == 0)
    {
      string str = X.substr(0, m);
      //reverse(str.begin(), str.end());
      return make_pair(m, str);
    }
    
    if(dp[m][n].first != -1)
    {
      return dp[m][n];
    }
    if(X[m-1] == Y[n-1])
    {
      pair<int, string> data = shortestCommonSupersequenceUtil(X, Y, m-1, n-1, dp);
      dp[m][n].first = 1+data.first;
      dp[m][n].second = data.second+X[m-1];
      return dp[m][n];
    }

    if(shortestCommonSupersequenceUtil(X, Y, m, n-1, dp) < shortestCommonSupersequenceUtil(X, Y, m-1, n, dp))
    {
      pair<int, string> data = shortestCommonSupersequenceUtil(X, Y, m, n-1, dp);
      dp[m][n].first = 1+data.first;
      dp[m][n].second = data.second+Y[n-1];
      return dp[m][n];
    }
    else
    {
      pair<int, string> data = shortestCommonSupersequenceUtil(X, Y, m-1, n, dp);
      dp[m][n].first = 1+data.first;
      dp[m][n].second = data.second+X[m-1];
      return dp[m][n];
    }
  }
public:
  // Function to find length of shortest common supersequence of two strings.
  pair<int,string> shortestCommonSupersequence(string X, string Y, int m, int n)
  {
    // code here
    vector<vector<pair<int, string>>> dp(m+1, vector<pair<int, string>>(n+1, make_pair(-1, "")));
    pair<int, string> data = shortestCommonSupersequenceUtil(X, Y, m, n, dp);
    //reverse(data.second.begin(), data.second. end());
    return data;
  }
};

//{ Driver Code Starts.

int main()
{
  string X("efgh"), Y("jghi");
  Solution obj;
  pair<int, string> data = obj.shortestCommonSupersequence(X, Y, X.size(), Y.size());
  cout << data.first << endl;
    cout << data.second << endl;
  return 0;
}

// } Driver Code Ends