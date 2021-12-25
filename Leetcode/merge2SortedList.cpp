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

ListNode *SortedMerge(ListNode *list1, ListNode *list2)
{

  ListNode *output;
  if (list1 == nullptr)
  {
    return list2;
  }
  if (list2 == nullptr)
  {
    return list1;
  }

  if (list1->val <= list2->val)
  {
    output = list1;
    output->next = SortedMerge(list1->next, list2);
  }
  else
  {
    output = list2;
    output->next = SortedMerge(list1, list2->next);
  }
  return output;
}
class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    ListNode *output = SortedMerge(list1, list2);
    return output;
  }
};