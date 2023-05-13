#include <iostream>

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

int heightutil ( Node* node )
{
  if (node == nullptr)
  {
    return 0;
  }

  int lHeight = heightutil ( node->left );
  int rHeight = heightutil ( node->right );

  return (1 + ((lHeight > rHeight) ? lHeight : rHeight));
}
int height ( struct Node* node )
{
  //Your code here
  return heightutil ( node );
}
