#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cfloat>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    return lowestCommonAncestorUtil(root, p, q);
  }

private:

  TreeNode *lowestCommonAncestorUtil(TreeNode *node, TreeNode *p, TreeNode *q)
  {
    if(node == nullptr)
    {
      return nullptr;
    }

    if(node == p || node == q)
    {
      return node;
    }

    TreeNode* lChild = lowestCommonAncestorUtil(node->left, p, q);
    TreeNode* rChild = lowestCommonAncestorUtil(node->right, p, q);

    if(lChild && rChild)
    {
      return node;
    }
    else if(lChild)
    {
      return lChild;
    }
    return rChild;
  }
};