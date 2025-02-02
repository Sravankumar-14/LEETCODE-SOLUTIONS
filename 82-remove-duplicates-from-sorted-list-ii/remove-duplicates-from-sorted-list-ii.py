# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = ListNode(0)
        temp = head
        head = prev
        while temp :
            count = 1
            while temp.next and temp.val == temp.next.val:
                count += 1
                temp = temp.next
            if count == 1:
                prev.next = temp
                prev = temp
            temp = temp.next
        prev.next = temp
        return head.next
                