#include <iostream>

using namespace std;

void BuildHeap(int arr[], int count)
{
  for (int i = 1; i < count; ++i)
  {
    int child = i;
    int parent = (child - 1) / 2;
    while (parent >= 0 && arr[parent] < arr[child])
    {
      swap(arr[parent], arr[child]);
        child = parent;
        parent = child - 1 / 2;
    }
  }
}

void HeapSort(int arr[], int count)
{
  BuildHeap(arr, count);

  for (int i = count - 1; i > 0; --i)
  {
    swap(arr[0], arr[i]);
    int parentId = 0;
    int lChild = 2 * parentId + 1;
    int rChild = 2 * parentId + 2;
    while (parentId < i)
    {
      int maxValIndex = parentId;
      if (lChild < count && arr[lChild] > arr[maxValIndex])
      {
        maxValIndex = lChild;
      }
      if (rChild < count && arr[rChild] > arr[maxValIndex])
      {
        maxValIndex = rChild;
      }
      if (maxValIndex != parentId)
      {
        swap(arr[parentId], arr[maxValIndex]);
        parentId = maxValIndex;
        lChild = 2 * parentId + 1;
        rChild = 2 * parentId + 2;
      }
      else
      {
        break;
      }
    }
  }
}
int main()
{
  int arr[] = {10, 20, 15, 17, 9, 21};
  int n = sizeof(arr) / sizeof(arr[0]);
  HeapSort(arr, n);
  for (int i = 0; i < n; i++)
  {
    cout<<arr[i]<<endl;
  }
  return 0;
}