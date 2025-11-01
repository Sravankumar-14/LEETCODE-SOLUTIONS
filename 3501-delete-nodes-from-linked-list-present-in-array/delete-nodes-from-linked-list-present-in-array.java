/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        HashSet<Integer> set = new HashSet<>();
        for(int num : nums) {
            set.add(num);
        }
        ListNode prev = new ListNode();
        ListNode start = prev;
        while(head != null) {
            int val = head.val;
            if(set.contains(val)) {
                head = head.next;
                continue;
            }
            prev.next = head;
            prev = prev.next;
            head = head.next;
        }
        prev.next = null;
        return start.next;
    }
}