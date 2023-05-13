#include "common.h"

int diameterUtil ( Node* node, int& maxDia )
{
  if (node == nullptr)
  {
    return 0;
  }

  int lDia = diameterUtil ( node->left, maxDia );
  int rDia = diameterUtil ( node->right, maxDia );

  maxDia = max ( maxDia, (lDia + rDia + 1) );
  return (1 + ((lDia > rDia) ? lDia : rDia));
}
int diameter ( struct Node* node )
{
  //Your code here
  int maxDia = INT_MIN;
  auto result = diameterUtil ( node, maxDia );
  return maxDia;
}

int main ()
{
  vector<int> data{ 1,2,3 };
  Node* root = BuildTree ( data );
  auto dia = diameter ( root );

  return 0;
}
