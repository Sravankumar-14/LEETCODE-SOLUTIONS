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

    public void inOrder(TreeNode root, ArrayList<Integer> list) {
        if(root == null) return;
        inOrder(root.left, list);
        list.add(root.val);
        inOrder(root.right, list);
    }

    public TreeNode constructBinarySearchTree(ArrayList<Integer> list, int low, int high) {
        if(low > high) return null;
        int mid = low + (high - low) / 2;
        TreeNode curr = new TreeNode(list.get(mid));
        curr.left = constructBinarySearchTree(list, low, mid-1);
        curr.right = constructBinarySearchTree(list, mid+1, high);
        return curr;
    }

    public TreeNode balanceBST(TreeNode root) {
        ArrayList<Integer> list = new ArrayList<>();
        inOrder(root, list);
        return constructBinarySearchTree(list, 0, list.size()-1);
    }
}