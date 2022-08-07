#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a binary tree node.
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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> result;
    if (root == nullptr)
    {
      return result;
    }

    queue<TreeNode *> levelQueue;
    levelQueue.push(root);
    levelQueue.push(nullptr);

    vector<int> tempVec;
    while (levelQueue.empty() == false)
    {
      TreeNode *temp = levelQueue.front();
      if (temp != nullptr)
      {
        levelQueue.pop();
        tempVec.push_back(temp->val);
        if (temp->left)
        {
          levelQueue.push(temp->left);
        }
        if (temp->right)
        {
          levelQueue.push(temp->right);
        }
      }
      else
      {
        levelQueue.pop();
        result.emplace_back(std::move(tempVec));
        tempVec.clear();
        if (levelQueue.empty() == false)
        {
          levelQueue.push(nullptr);
        }
      }
    }
    return result;
  }
};