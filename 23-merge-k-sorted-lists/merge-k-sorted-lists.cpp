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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>vec;
        for(auto i : lists)
        {
            ListNode* temp = i;
            while(temp)
            {
                vec.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(vec.begin(),vec.end());
        int a = 0;
        int n = vec.size();
        ListNode * head = new ListNode(0);
        ListNode* temp = head;
        while(a < n)
        {
            ListNode* newNode = new ListNode(vec[a]);
            a++;
            temp->next = newNode;
            temp = temp->next;
        }
        return head->next;
    }
};