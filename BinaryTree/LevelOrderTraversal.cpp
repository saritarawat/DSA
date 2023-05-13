#include "common.h"

vector<int> levelOrder ( Node* node )
{
  //Your code here
  vector<int> result;
  queue<Node*> myQueue;
  myQueue.push ( node );

  while (myQueue.empty () == false)
  {
    Node* temp = myQueue.front ();
    myQueue.pop ();
    result.push_back( temp->data );
    
    if (temp->left)
    {
      myQueue.push ( temp->left );
    }

    if (temp->right)
    {
      myQueue.push ( temp->right );
    }
  }
  return result;
}

int  main()
{
  return 0;
}
