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
int MOD=1e9+7;
  Solution()
  {
    vowelIntMap['a'] = 0;
    vowelIntMap['e'] = 1;
    vowelIntMap['i'] = 2;
    vowelIntMap['o'] = 3;
    vowelIntMap['u'] = 4;
    vowelIntMap['z'] = 5;
  }
  int countVowelPermutation(int n)
  {
    if (n == 0)
    {
      return 0;
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(6, -1));

    int val = countVowelPermutationUtil(1, n, dp, 'z')%MOD;
    return val;
  }

private:
  unordered_map<char, int> vowelIntMap;
  long long int countVowelPermutationUtil(int id, int n, vector<vector<long long>> &dp, char lastChar)
  {
    if (id > n)
    {
      return 1;
    }

    if (dp[id][vowelIntMap[lastChar]] != -1)
    {
      return dp[id][vowelIntMap[lastChar]];
    }

    long long int count = 0;
    if (lastChar == 'a')
    {
      count+=countVowelPermutationUtil(id+1, n, dp, 'e');
    }
    else if (lastChar == 'e')
    {
      count+=countVowelPermutationUtil(id+1, n, dp, 'a');
      count+=countVowelPermutationUtil(id+1, n, dp, 'i');
    }
    else if (lastChar == 'i')
    {
      count+=countVowelPermutationUtil(id+1, n, dp, 'a');
      count+=countVowelPermutationUtil(id+1, n, dp, 'e');
      count+=countVowelPermutationUtil(id+1, n, dp, 'o');
      count+=countVowelPermutationUtil(id+1, n, dp, 'u');
    }
    else if (lastChar == 'o')
    {
      count+=countVowelPermutationUtil(id+1, n, dp, 'i');
      count+=countVowelPermutationUtil(id+1, n, dp, 'u');
    }
    else if (lastChar == 'u')
    {
      count+=countVowelPermutationUtil(id+1, n, dp, 'a');
    }
    else
    {
      count+=countVowelPermutationUtil(id+1, n, dp, 'a');
      count+=countVowelPermutationUtil(id+1, n, dp, 'e');
      count+=countVowelPermutationUtil(id+1, n, dp, 'i');
      count+=countVowelPermutationUtil(id+1, n, dp, 'o');
      count+=countVowelPermutationUtil(id+1, n, dp, 'u');
    }
    dp[id][vowelIntMap[lastChar]] = count%MOD;

    return dp[id][vowelIntMap[lastChar]];
  }
};

int main()
{
  Solution sol;
  cout << "Ans : "<<sol.countVowelPermutation(144)<<endl;
  return 0;
}