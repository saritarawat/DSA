#include <iostream>
using namespace std;

class Solution
{
private:

bool isValidPages(int A[], int N, int M, long long maxPages)
{
  long long curPagesCount = 0;
  int curStudents = 1;

  for(int i = 0; i < N; ++i)
  {
    if(A[i] > maxPages)
    {
      return false;
    }

    if(curPagesCount+A[i] > maxPages)
    {
      curStudents++;
      curPagesCount = A[i];
    }
    else
    {
      curPagesCount+=A[i];
    }

    if(curStudents > M)
    {
      return false;
    }
  }
  return true;
}

public:
  int findPages(int A[], int N, int M)
  {
    // code here
    if(N < M)
    {
      return -1;
    }
    long long sum = 0;
    for(int i = 0; i < N; ++i)
    {
      sum+=A[i];
    }
    long long start = 0;
    long long end = sum;
    long long int result = 0;
    while(start <= end)
    {
      long long mid = start+(end-start)/2;

      if(isValidPages(A, N, M, mid))
      {
        result = mid;
        end = mid-1;
      }
      else
      {
        start = mid+1;
      }
    }
    return result;
  }
};

int main()
{
  Solution ob;
  int A[] = {10,20,30,40};
  cout << ob.findPages(A, 4, 2) << endl;
  return 0;
}
