//{ Driver Code Starts
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// } Driver Code Ends
int solve(int i, int j, int count, string str1, string str2)
    {
 
        if (i == 0 || j == 0)
        {
            return count;
        }
 
        if (str1[i - 1] == str2[j - 1])
        {
            count = solve(i - 1, j - 1, count + 1, str1, str2);
        }
        int count1 = solve(i, j - 1, 0, str1, str2);

        int count2 = solve(i - 1, j, 0, str1, str2);

        count = max(count, max(count1,count2));
        return count;
    }
    int lcsubstr(string s1, string s2){
        int ans = solve(s1.size(), s2.size(), 0, s1, s2);
        return ans;
    }
class Solution
{
  int longestCommonSubstrUtil(string S1, string S2, int n, int m, int count, vector<vector<vector<int>>> &dp)
  {
    // your code here
    if (n == 0 || m == 0)
    {
      return count;
    }

    // if (dp[n][m][count] != -1)
    // {
    //   return dp[n][m][count];
    // }

    if (S1[n - 1] == S2[m - 1])
    {
      return dp[n][m][count] = longestCommonSubstrUtil(S1, S2, n - 1, m - 1, count + 1, dp);
    }

    int val1 = longestCommonSubstrUtil(S1, S2, n, m - 1, 0, dp);
    int val2 = longestCommonSubstrUtil(S1, S2, n - 1, m, 0, dp);
    return dp[n][m][count] = max(count, max(val1, val2));
  }

public:
  int longestCommonSubstr(string S1, string S2, int n, int m)
  {
    // your code here
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(max(n, m) + 1, -1)));
    return longestCommonSubstrUtil(S1, S2, n, m, 0, dp);
  }
};

//{ Driver Code Starts.

int main()
{
  string s1("KXCGMTMVVGFQQWSPD"), s2("JXZADDUKVLQPKUZJZHWSUTPCAFSYAIBJHAMMEGWBTPQELRNKBLDXGUZGCSEC");
  cout << lcsubstr(s1, s2) << endl;
  return 0;
  Solution ob;

  cout << ob.longestCommonSubstr(s1, s2, s1.length(), s2.length()) << endl;
  return 0;
}
// Contributed By: Pranay Bansal

// } Driver Code Ends