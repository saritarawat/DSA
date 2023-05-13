#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  vector<Node *> neighbors;
  Node()
  {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val)
  {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors)
  {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution
{
  private:
  Node *cloneGraph(Node *node, unordered_map<Node*, Node*>& visited)
  {
    if(node == nullptr)
    {
      return;
    }
    if(visited[node] != nullptr)
    {
      return visited[node];
    }

    Node* clone = visited[node] = new Node(node->val);
    for(auto itr: node->neighbors)
    {
      Node* clonedNeighbour = cloneGraph(itr, visited);
      if(clonedNeighbour != nullptr)
      {
        visited[node]->neighbors.push_back(clonedNeighbour);
      }
    }
    return clone;
  }
public:
  Node *cloneGraph(Node *node)
  {
    unordered_map<Node*, Node*> visited;
    return cloneGraph(node, visited);
  }
};


int main()
{
  Solution sol;
  return 0;
}