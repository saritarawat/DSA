//{ Driver Code Starts
#include "common.h"

struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};
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
  Node *root = new Node(stoi(ip[0]));

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
      currNode->left = new Node(stoi(currVal));

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
      currNode->right = new Node(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}

bool isCousins(Node *root, int x, int y);

int main()
{
  string s("1 2 3");
  Node *root = buildTree(s);
  int x = 2;
  int y = 3;
  cout << isCousins(root, x, y) << endl;
  return 1;
}
// } Driver Code Ends

/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
bool isCousins(Node *root, int a, int b)
{
  // add code here.
  if(root == nullptr)
  {
    return false;
  }
  queue<Node *> bfsQueue;
  bool aFound = false;
  bool bFound = false;
  bfsQueue.push(root);

  while (bfsQueue.empty() == false)
  {
    int size = bfsQueue.size();
    while (size > 0)
    {
      --size;
      Node* temp = bfsQueue.front();
      bfsQueue.pop();

      if(temp->left && temp->right)
      {
        if (temp->left->data == a || temp->right->data == a)
        {
          aFound == true;
        }

        if (temp->left->data == b || temp->right->data == b)
        {
          bFound == true;
        }
        if(aFound && bFound)
        {
          return true;
        }
      }
      else if(temp->left)
      {

      }
      else
      {

      }
    }
    
  }
  


  return false;
}