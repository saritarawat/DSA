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
  ListNode *detectCycle(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return nullptr;
    }

    if(head == head->next)
    {
      return head;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast)
      {
        break;
      }
    }

    if (slow == fast)
    {
      slow = head;
      while (slow != fast)
      {
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
    else
    {
      return nullptr;
    }
  }
};

int main()
{
  Solution sol;
  ListNode* head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next;

  ListNode* t = sol.detectCycle(head);
  return 0;
}