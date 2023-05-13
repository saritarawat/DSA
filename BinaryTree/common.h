#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

struct Node
{
  int data;
  struct Node* left;
  struct Node* right;

  Node ( int x )
  {
    data = x;
    left = right = NULL;
  }
};

Node* BuildTree(vector<int>& data)
{
  if (data.size () == 0)
  {
    return nullptr;
  }

  Node* temp = new Node ( data[0] );
  queue<Node*> myQueue;
  myQueue.push ( temp );
  int index = 1;
  while (myQueue.empty() ==false && index < data.size())
  {
    Node* tempNode = myQueue.front ();
    myQueue.pop ();

    if (data[index] != -1)
    {
      tempNode->left = new Node ( data[index] );
    }
    index++;
    if (data[index] != -1)
    {
      tempNode->right = new Node ( data[index] );
    }
    index++;
  }
  return temp;
}

Node* BuildTree(vector<int>&& data)
{
  if (data.size () == 0)
  {
    return nullptr;
  }

  Node* temp = new Node ( data[0] );
  queue<Node*> myQueue;
  myQueue.push ( temp );
  int index = 1;
  while (myQueue.empty() ==false && index < data.size())
  {
    Node* tempNode = myQueue.front ();
    myQueue.pop ();

    if (data[index] != -1)
    {
      tempNode->left = new Node ( data[index] );
      myQueue.push(tempNode->left);
    }
    index++;
    if (data[index] != -1)
    {
      tempNode->right = new Node ( data[index] );
      myQueue.push(tempNode->right);
    }
    index++;
  }
  return temp;
}