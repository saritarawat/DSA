//{ Driver Code Starts
#include <iostream>
#include <vector>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
private:
  void merge(vector<pair<int, int>> &arrIndexPair, int low, int mid, int high, vector<int> &result)
  {
    vector<pair<int, int>> temp(high - low + 1);
    int i = low;
    int j = mid + 1;
    int k = 0;
    int count = 0;
    while (i <= mid && j <= high)
    {
      if (arrIndexPair[i].first <= arrIndexPair[j].first)
      {
        result[arrIndexPair[i].second] += count;
        temp[k++] = arrIndexPair[i++];
      }
      else
      {
        count++;
        temp[k++] = arrIndexPair[j++];
      }
    }

    while (i <= mid)
    {
      result[arrIndexPair[i].second] += count;
      temp[k++] = arrIndexPair[i++];
    }
    while (j <= high)
    {
      temp[k++] = arrIndexPair[j++];
    }

    i = low;
    for (int l = 0; l < temp.size(); ++l)
    {
      arrIndexPair[low++] = temp[l];
    }
  }

  void mergeSort(vector<pair<int, int>> &arrIndexPair, int low, int high, vector<int> &result)
  {
    // code here
    if (low >= high)
    {
      return;
    }

    int mid = low + (high - low) / 2;
    mergeSort(arrIndexPair, low, mid, result);
    mergeSort(arrIndexPair, mid + 1, high, result);
    merge(arrIndexPair, low, mid, high, result);
  }

public:
  vector<int> constructLowerArray(int *arr, int n)
  {
    // code here
    if (n == 0 || n == 1)
    {
      vector<int> result1(n, 0);
      return result1;
    }

    vector<pair<int, int>> arrIndexPair;
    for (int i = 0; i < n; ++i)
    {
      arrIndexPair.push_back(make_pair(arr[i], i));
    }

    vector<int> result(n, 0);
    mergeSort(arrIndexPair, 0, n - 1, result);
    return result;
  }
};

//{ Driver Code Starts.

int main()
{
  int arr[] = {12, 1, 2, 3, 0, 11, 4};
  Solution ob;
  auto ans = ob.constructLowerArray(arr, 7);
  for (auto x : ans)
  {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}

// } Driver Code Ends