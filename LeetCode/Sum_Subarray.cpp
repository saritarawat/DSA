//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // Function to find a continuous sub-array which adds up to a given number.
  vector<int> subarraySum(int arr[], int n, long long s)
  {
    long long sum = 0;
    queue<int> data;
    vector<int> result;
    for(int i = 0; i < n; ++i)
    {
      if(arr[i] == s)
      {
        result.push_back(i+1);
        result.push_back(i+1);
        return result;
      }
      else if(arr[i] > s)
      {
        while(data.empty() == false)
        {
          data.pop();
        }
      }
      else
      {
        while (data.empty() == false && (sum+arr[i]) > s)
        {
          sum-=arr[data.front()];
          data.pop();
        }
        sum+=arr[i];
        data.push(i);
      }
      if(sum == s && )
      {
        result.push_back(data.front()+1);
        result.push_back(i+1);
        break;
      }
    }
    return result;
  }
};

//{ Driver Code Starts.

int main()
{
  Solution ob;
  vector<int> res;
  int arr[] = {1,2,3,7,5};
  res = ob.subarraySum(arr, 5, 12);

  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
  return 0;
}
// } Driver Code Ends