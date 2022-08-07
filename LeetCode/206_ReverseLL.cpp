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
  ListNode *reverseList(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }
    ListNode *cur = head;
    ListNode *prev = nullptr;

    while (cur)
    {
      ListNode *next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    head->next = nullptr;
    return prev;
  }

  ListNode *reverseListRecursiveUtil(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }

    ListNode *next = head->next;
    ListNode *root = reverseListRecursiveUtil(head->next);

    next->next = head;

    return root;
  }

  ListNode *reverseListRecursive(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }

    ListNode* root = reverseListRecursiveUtil(head);
    head->next = nullptr;
    return root;
  }
};

int main()
{
  Solution sol;

  return 0;
}