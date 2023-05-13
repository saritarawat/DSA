#include "common.h"

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
  int data;
  Node *left;
  Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
  Node *temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
  // Corner Case
  if (str.length() == 0 || str[0] == 'N')
    return NULL;

  // Creating vector of strings from input
  // string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);

  // Create the root of the tree
  Node *root = newNode(stoi(ip[0]));

  // Push the root to the queue
  queue<Node *> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size())
  {

    // Get and remove the front of the queue
    Node *currNode = queue.front();
    queue.pop();

    // Get the current node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N")
    {

      // Create the left child for the current node
      currNode->left = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->left);
    }

    // For the right child
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];

    // If the right child is not null
    if (currVal != "N")
    {

      // Create the right child for the current node
      currNode->right = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}

// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution
{
public:


    void PrintLeft(Node* node, vector<int>& list)
    {
      if(node == nullptr)
      {
          return;
      }
      
      if(node->left != nullptr)
      {
          list.push_back(node->data);
          PrintLeft(node->left, list);
      }
      else if(node->right != nullptr)
      {
        list.push_back(node->data);
          PrintLeft(node->right, list);  
      }
    }
    void PrintRight(Node* node, vector<int>& list)
    {
      if(node == nullptr)
      {
          return;
      }
      
      if(node->right != nullptr)
      {
          PrintRight(node->right, list);
          list.push_back(node->data);
      }
      else if(node->left != nullptr)
      {
          PrintRight(node->left, list);
          list.push_back(node->data);  
      }  
    }
    void PrintLeaves(Node* node, vector<int>& list)
    {
        if(node == nullptr)
      {
          return;
      }
      PrintLeaves(node->left, list);
      if(node->left == nullptr && node->right == nullptr)
      {
        list.push_back(node->data);     
      }
      PrintLeaves(node->right, list);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> list;
        if(root == nullptr)
        return list;
        
        list.push_back(root->data);
        
        PrintLeft(root->left, list);
        PrintLeaves(root->left, list);
        PrintLeaves(root->right, list);
        PrintRight(root->right, list);
        return list;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main()
{
  string s("1 2 3 4 5 6 7 N N 8 9 N N N N");
  Node *root = buildTree(s);
  Solution ob;
  vector<int> res = ob.boundary(root);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
// } Driver Code Ends