#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Permute(string str, int l, int r, vector<string>& result)
{
  if(l == r)
  {
    result.push_back(str);
    return;
  }

  for( int i = l; i <= r; ++i)
  {
    swap(str[i], str[l]);
    Permute(str, l+1, r, result);
  }
}

void Combination(string str, int l, int r, vector<string>& result)
{
  if(l == r)
  {
    result.push_back(str);
    return;
  }

  for( int i = l; i <= r; ++i)
  {
    swap(str[i], str[l]);
    Combination(str, l+1, r, result);
    swap(str[i], str[l]);
  }
}

int main()
{
  vector<string> resultP;
  vector<string> resultC;
  string str("ABC");

  Permute(str, 0, str.length()-1, resultP);
  Combination(str, 0, str.length()-1, resultC);
  return 0;
}