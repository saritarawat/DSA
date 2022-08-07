#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cfloat>
#include <stack>
using namespace std;

class Solution {
public:
    int fib(int n) 
    {
      if(n == 0 || n == 1)    
      {
        return n;
      }

      int last[2] = {0, 1};
      
      for(int i = 2; i <= n; ++i)
      {
        int sum = last[0]+last[1];
        last[0] = last[1];
        last[1] = sum;
      }
      return last[1];
    }
};


int main()
{
  cout<<Solution().fib(4)<<endl;
  return 0;
}