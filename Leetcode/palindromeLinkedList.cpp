/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  bool isPalindrome(ListNode *head)
  {
    ListNode *p = head;
    std::stack<int> s;
    while (p != nullptr)
    {
      s.push(p->val);
      p = p->next;
    }

    while (head != nullptr)
    {
      int n = s.top();
      s.pop();
      if (head->val != n)
      {
        return false;
      }
      head = head->next;
    }
    return true;
  }
};