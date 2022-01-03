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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode output_head;
        ListNode* output = &output_head;
        int sum = 0;
        while (l1 || l2 || sum){
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2){
                sum += l2->val;
                l2 = l2->next;
            }
            if (sum >= 10){
                output->next = new ListNode(sum-10);
            }
            else{
                output->next = new ListNode(sum);
            }
            
            output = output->next;
            sum = (sum > 9) ? 1 : 0;
        }
        
        return output_head.next;
    }
};