/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    boolean isBalanced = true;
    int rec(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int left = rec(root.left);
        int right = rec(root.right);
        if(Math.abs(left - right) > 1) {
            isBalanced = false;
        }
        return Math.max(left, right) + 1;
    }
    public boolean isBalanced(TreeNode root) {
        rec(root);
        return isBalanced;
    }
}