//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <vector>

using namespace std;
double MedianOfArrays(vector<int> &array1, vector<int> &array2);

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  double MedianOfArrays(vector<int> &array1, vector<int> &array2)
  {
    // Your code goes here
    int len1 = array1.size();
    int len2 = array2.size();
    int count = (len1 + len2) / 2;
    int count1 = 0;
    int cur = 0;
    int prev = 0;
    int i = 0;
    int j = 0;

    while (count1 <= count)
    {
      if (i < len1 && j < len2)
      {
        prev = cur;
        if (array1[i] < array2[j])
        {
          cur = array1[i++];
        }
        else
        {
          cur = array2[j++];
        }
        count1++;
      }
      else if (i < len1)
      {
        cur = array1[i + count - count1];
        if (j - 1 >= 0 && i + count - count1 - 1 >= 0)
        {
          prev = max(array2[j - 1], array1[i + count - count1 - 1]);
        }
        else if (j - 1 >= 0)
        {
          prev = array2[j - 1];
        }
        else if (i + count - count1 - 1 >= 0)
        {
          prev = array1[i + count - count1 - 1];
        }
        break;
      }
      else
      {
        cur = array2[j + count - count1];
        if (j + count - count1 - 1 >= 0 && i - 1 >= 0)
        {
          prev = max(array1[i - 1], array2[j + count - count1 - 1]);
        }
        else if (j + count - count1 - 1 >= 0)
        {
          prev = array2[j + count - count1 - 1];
        }
        else if (i - 1 >= 0)
        {
          prev = array1[i - 1];
        }
        break;
      }
    }

    if ((len1 + len2) % 2 == 0)
    {
      return (prev + cur) / 2.0;
    }
    else
    {
      return cur;
    }
  }
};

//{ Driver Code Starts.

int main()
{
  vector<int> array1;
  vector<int> array2({1, 2});
  Solution ob;
  cout << ob.MedianOfArrays(array1, array2) << endl;
  return 0;
}

// } Driver Code Ends