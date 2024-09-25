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
    ListNode* rotate(ListNode* head, int len)
    {
        ListNode* jump = head;
        ListNode* start = head;
        for(int i=0; i<len; i++) jump = jump->next;
        while(jump->next)
        {
            jump = jump->next;
            start = start->next;
        }
        jump->next = head;
        ListNode* temp = start->next;
        start->next = NULL;
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {

        if(k == 0 || head == nullptr) return head;
        int count = 0;
        ListNode* temp = head;
        while(temp)
        {
            temp = temp->next;
            count++;
        }
        // if(k % count == 0) return head;
        return rotate(head,k % count);
    }
};