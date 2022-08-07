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
  string getHint(string secret, string guess)
  {
    int secretLen = secret.length();
    int guessLen = guess.length();

    if(secret.size() == 0 || guess.size() == 0)
    {
      return "0A0B";
    }

    int bullCount =0;
    int cowCount =0;
    unordered_map<char, int> secretCharCount;
    unordered_map<char, int> guessCharCount;

    int i = 0;
    int j = 0;

    while(i < secretLen || j < guessLen)
    {
      if(i < secretLen && j < guessLen)
      {
        if(secret[i] == guess[j])
        {
          bullCount++;
          i++;
          j++;
        }
        else
        {
          secretCharCount[secret[i++]]++;
          guessCharCount[guess[j++]]++;
        }
      }
      else if(i < secretLen)
      {
        secretCharCount[secret[i++]]++;
      }
      else
      {
        guessCharCount[guess[j++]]++;
      }
    }



    for(auto itr = secretCharCount.begin(); itr != secretCharCount.end(); ++itr)
    {
      if(guessCharCount[itr->first] > 0)
      {
        int val =min(guessCharCount[itr->first], itr->second);
        cowCount+=val;
        guessCharCount[itr->first] = guessCharCount[itr->first]-val;
      }
    }
    
    string str = to_string(bullCount)+"A"+to_string(cowCount)+"B";
    return str;

  }
};

int main()
{
  cout << Solution().getHint("1123", "0111") << endl;
  return 0;
}