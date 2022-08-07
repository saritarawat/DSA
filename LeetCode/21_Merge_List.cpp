#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    ListNode* temp1 = list1;
    ListNode* temp2 = list2;

    ListNode dummy;
    ListNode* cur = &dummy;

    while (temp1 && temp2)
    {
      if(temp1->val < temp2->val)
      {
        cur->next = temp1;
        temp1 = temp1->next;
      }
      else
      {
        cur->next = temp2;
        temp2 = temp2->next;
      }
      cur = cur->next;
    }

    if(temp1)
    {
      cur->next = temp1;
    }
    
    if(temp2)
    {
      cur->next = temp2;
    }
    return dummy.next;
  }
};

int main()
{
  Solution sol;
  ListNode* node1 = new ListNode(1);
  node1->next = new ListNode(2);
  node1->next->next = new ListNode(4);


  ListNode* node2 = new ListNode(1);
  node2->next = new ListNode(3);
  node2->next->next = new ListNode(4);

  ListNode* root = sol.mergeTwoLists(node1, node2);

  while (root)
  {
    cout<<root->val<<endl;
    root = root->next;
  }
  

  return 0;
}