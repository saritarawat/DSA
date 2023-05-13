//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
int KDistanceNodesUtil(Node* node, int target, int k, int level, vector<int>& result)
{
  if(node == nullptr || level > k)
  {
    return 0;
  }

  if(level == k)
  {
    result.push_back(node->data);
    return;
  }
  if(level == 0)
  {
     if(node->data == target)
     {
      level = 1;
     }
  }
  else
  {
    level++;
  }
  int res = KDistanceNodesUtil(node->left, target, k, level, result);
  if(res > 0)
  {
    level++;
  }
  res = KDistanceNodesUtil(node->left, target, k, level, result);
  if(node->data == target)
  {
    return 1;
  }
  return 
}
public:
  vector<int> KDistanceNodes(Node *root, int target, int k)
  {
    // return the sorted vector of all nodes at k dist
  }
};

//{ Driver Code Starts.

int main()
{

  Solution x = Solution();

  string s("20 8 22 4 12 N N N N 10 14");
  Node *head = buildTree(s);

  vector<int> res = x.KDistanceNodes(head, 8, 2);

  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
  return 0;
}

// } Driver Code Ends