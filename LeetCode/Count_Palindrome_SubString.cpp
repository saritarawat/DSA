//{ Driver Code Starts
// Initial Template for c++

#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
  bool isPalindrome(string& str, int l, int r)
  {
    int i = l;
    int j = r;

    while (i < j)
    {
      if(str[i] != str[j])
      {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }

  int palindromicPartitionUtil(string& str, int l, int r, vector<vector<int>>& dp)
  {
    if(l >= r || isPalindrome(str, l, r))
    {
      return 0;
    }
    if(dp[l][r] != -1)
    {
      return dp[l][r];
    }

    int count = INT_MAX;
    for(int k = l; k < r; ++k)
    {
      int curCount = palindromicPartitionUtil(str, l, k, dp)+palindromicPartitionUtil(str, k+1, r, dp) +1;
      count = min(count, curCount);
    }
    dp[l][r] = count;
    return count;
  }
public:
  int palindromicPartition(string str)
  {
    // code here
    vector<vector<int>> dp(str.length(), vector<int>(str.length(), -1));
    return palindromicPartitionUtil(str, 0, str.length()-1, dp);
  }
};


int main()
{
  string str("ababbbabbababa");
  Solution ob;
  cout << ob.palindromicPartition(str) << "\n";
  return 0;
}
// } Driver Code Ends