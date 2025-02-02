# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 == None : 
            return list2
        head = list1
        prev = ListNode(101)
        while list1 and list2:
            if list1.val <= list2.val :
                prev = list1
                list1 = list1.next
            else:
                if prev.val == 101 :
                    head = list2
                temp2 = list2.next
                list2.next = list1
                prev.next = list2
                prev = list2
                list2 = temp2
        if list2 :
                prev.next = list2
        return head