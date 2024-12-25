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
 import java.util.Vector;
class Solution {
    public static int maxHeight(TreeNode root)
    {
        if(root == null) return 0;
        return Math.max(maxHeight(root.left) , maxHeight(root.right)) + 1;
    }

    public void buildVector(TreeNode root, Vector<Integer> vec, int level)
    {
        if(root == null) return;
        buildVector(root.left,vec, level+1);
        buildVector(root.right, vec, level+1);
        vec.set(level, Math.max(vec.get(level) , root.val));
    }

    public List<Integer> largestValues(TreeNode root) {
        int n = maxHeight(root);
        Vector<Integer>vec = new Vector<>();
        for(int i=0; i<n; i++)
        {
            vec.add(Integer.MIN_VALUE);
        }
        buildVector(root,vec,0);
        return vec;
    }
}