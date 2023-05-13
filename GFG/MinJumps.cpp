//{ Driver Code Starts
#include "common.h"

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
  int minJumps(int arr[], int n)
  {
    // Your code here
    int jumps = 0;
    int maxIndex = arr[0];


    for(int i = 1; i < n; ++i)
    {
      if(maxIndex == i)
      {
        jumps++;
      }
      maxIndex = max(maxIndex, i+arr[i]);
      if(maxIndex >= n)
      {
        
      }
      if(maxIndex == i)
      {
        return -1;
      }
    }
    return jumps;
  }
};

//{ Driver Code Starts.

int main()
{
  Solution obj;
  int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

  cout << obj.minJumps(arr, 11) << endl;
  return 0;
}

// } Driver Code Ends