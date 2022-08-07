#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cfloat>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
  string decodeString(string s)
  {
    if(s.length() == 0)
    {
      return "";
    }
    stack<string> myData;
    for(int i = 0; i < s.length(); ++i)
    {
      if(s[i] != ']')
      {
        string s1(1, s[i]);
        myData.top().append(std::move(s1));
      }
      else
      {
        string temp;
        while(myData.empty() == false && myData.top() != "[")
        {
          temp.append(myData.top());
          myData.pop();
        }
        myData.pop();
        reverse(temp.begin(), temp.end());
        int count = stoi(myData.top());
        myData.pop();
        string result = temp;
        for(int i = 1; i < count; ++i)
        {
          result+=temp;
        }
        myData.push(result);
      }
    }

    string str = ReverseStack(myData);
    return str;
  }

  private:
  string ReverseStack(stack<string>& data)
  {
    if(data.empty())
    {
      return "";
    }

    string str = data.top();
    data.pop();
    string str1 = ReverseStack(data);

    str1.append(str);

    return str1;
  }
};



int main()
{
  cout << Solution().decodeString("100[leetcode]") << endl;
  return 0;
}