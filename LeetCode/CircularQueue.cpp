#include "common.h"

class MyCircularQueue
{
  int mSize = 0;
  int mCurSize = 0;
  int mFrontIndex = -1;
  int mLastIndex = -1;
  vector<int> mData;

public:
  MyCircularQueue(int k)
  {
    mData.resize(k);
    mSize = k;
  }

  bool enQueue(int value)
  {
    if (isFull())
    {
      return false;
    }
    mLastIndex = (mLastIndex + 1) % mSize;
    if (mFrontIndex == -1)
    {
      mFrontIndex = 0;
    }
    mData[mLastIndex] = value;
    mCurSize++;
    return true;
  }

  bool deQueue()
  {
    if (isEmpty())
    {
      return false;
    }
    if (mFrontIndex == mLastIndex)
    {
      mFrontIndex = mLastIndex = -1;
    }
    else
    {
      mFrontIndex = (mFrontIndex + 1) % mSize;
    }
    mCurSize--;
    return true;
  }

  int Front()
  {
    if (isEmpty())
    {
      return -1;
    }
    return mData[mFrontIndex];
  }

  int Rear()
  {
    if (isEmpty())
    {
      return -1;
    }
    return mData[mLastIndex];
  }

  bool isEmpty()
  {
    return (mCurSize == 0);
  }

  bool isFull()
  {
    return (mCurSize==mSize);
  }
};

int main()
{
  MyCircularQueue myCircularQueue(2);
  myCircularQueue.enQueue(1); // return True
  myCircularQueue.enQueue(2); // return True

  myCircularQueue.deQueue();  // return True

  myCircularQueue.enQueue(3); // return True
  
  myCircularQueue.deQueue();  // return True

  myCircularQueue.enQueue(3); // return True
  
  myCircularQueue.deQueue();  // return True

  myCircularQueue.enQueue(3); // return True
  
  myCircularQueue.deQueue();  // return True

  myCircularQueue.Front();

  return 0;
}
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */