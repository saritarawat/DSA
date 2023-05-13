#include <iostream>
#include <vector>
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
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    if(nums.size() == 0)
    {
      return nullptr;
    }

    return BuildBalancedBST(nums, 0, nums.size()-1);
  }

  private:

  TreeNode* BuildBalancedBST(vector<int> &nums, int low, int high)
  {
    if(low > high)
    {
      return nullptr;
    }

    int mid = low+(high-low)/2;
    TreeNode* node = new TreeNode(nums[mid]);

    node->left = BuildBalancedBST(nums, low, mid-1);
    node->right = BuildBalancedBST(nums, mid+1, high);
    return node;
  }
};