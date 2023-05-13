#include "common.h"

vector<int> reverselevelOrder ( Node* node )
{
  //Your code here
  vector<int> result;
  queue<Node*> myQueue;
  myQueue.push ( node );

  while (myQueue.empty () == false)
  {
    Node* temp = myQueue.front ();
    myQueue.pop ();
    result.push_back ( temp->data );

    if (temp->right)
    {
      myQueue.push ( temp->right );
    }

    if (temp->left)
    {
      myQueue.push ( temp->left );
    }
  }
  reverse ( result.begin (), result.end () );
  return result;
}
