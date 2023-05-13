//{ Driver Code Starts
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool isBST(Node* n, int lower, int upper)
{
    if (!n) return true;
    if ( n->data <= lower || n->data >= upper ) return false;
    return (  isBST( n->left, lower, n->data )  &&  isBST( n->right, n->data, upper )  );
}

bool compare( Node* a, Node* b, vector<pair<int, int>> &mismatch )
{
    if ( !a && !b ) return true;
    if ( !a || !b ) return false;

    if ( a->data != b->data )
        mismatch.push_back( pair<int, int> (a->data, b->data) );

    return ( compare( a->left, b->left, mismatch ) && compare( a->right, b->right, mismatch ) );
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
    private:
    void correctBSTUtil(Node* node, long long int minVal, long long maxVal, Node*& n1, Node*& n2)
    {
        if(node == nullptr)
        {
            return;
        }
        bool minValFaluty = false;
        bool maxValFaluty = false;
        if(node->data<= minVal || node->data >= maxVal)
        {
            minValFaluty = node->data<= minVal;
            maxValFaluty = node->data >= maxVal;
            if(n1 == nullptr)
            {
                n1 = node;
            }
            else
            {
                n2 = node;
            }
            if(n1 && n2)
            {
                return;
            }
        }
        
        correctBSTUtil(node->left,minVal, maxValFaluty?maxVal:node->data, n1, n2);
        if(n1 && n2)
        {
                return;
        }
        correctBSTUtil(node->right, minValFaluty?minVal:node->data, maxVal, n1, n2);
    }
  public:
    void correctBST( struct Node* root )
    {
        // add code here.
        if(root == nullptr)
        {
            return;
        }
        Node* n1 = nullptr;
        Node* n2 = nullptr;
        correctBSTUtil(root, LLONG_MIN, LLONG_MAX, n1, n2);
        
        if(n1 && n2)
        {
            swap(n1->data, n2->data);
        }
        else if(n1)
        {
            swap(n1->data, root->data);
        }
        
    }
};


//{ Driver Code Starts.

int main()
{
    string s("2 1 83 N 3 47 96 4 N 6");

        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);

        Solution ob;
        ob.correctBST(root);

        // check 1: is tree now a BST
        if ( ! isBST(root, INT_MIN, INT_MAX) )
        {
            cout << "0\n";
        }

        // check 2: comparing with duplicate tree

        vector<pair<int, int>> mismatch;
        // a vector to store data of mismatching nodes

        if ( ! compare( root, duplicate, mismatch) )
        {
            // false output from this function indicates change in structure of tree
            cout << "0\n";
        }

        // finally, analysing the mismatching nodes
        if ( mismatch.size() != 2 || mismatch[0].first != mismatch[1].second || mismatch[0].second != mismatch[1].first )
            cout << "0\n";
        else cout << "1\n";
    return 0;
}

// } Driver Code Ends