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
  bool isValidBST(TreeNode *root)
  {
    return isValidBSTUtil(root, LLONG_MIN, LLONG_MAX);
  }

private:
  bool isValidBSTUtil(TreeNode *root, long long minVal, long long maxVal)
  {
    if(root == nullptr)
    {
      return true;
    }

    if(root->val <= minVal || root->val >= maxVal)
    {
      return false;
    }

    return (isValidBSTUtil(root->left, minVal, root->val) && isValidBSTUtil(root->right, root->val, maxVal));
  }
};