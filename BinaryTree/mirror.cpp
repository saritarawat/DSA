#include "common.h"

void invertTreeUtil(Node* node)
{
  if(node == nullptr)
  {
    return;
  }

  swap(node->left, node->right);
  invertTreeUtil(node->left);
  invertTreeUtil(node->right);
}
Node *invertTree(Node *root)
{
  invertTreeUtil(root);
  return root;
}

int main()
{
  Node* root = BuildTree({4,2,7,1,3,6,9});
  root = invertTree(root);
  return 0;
}