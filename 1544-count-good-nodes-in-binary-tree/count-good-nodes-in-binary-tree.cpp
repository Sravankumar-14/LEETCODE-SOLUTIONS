/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void rec(TreeNode* root, int maxValue, int & count)
    {
        if(root == NULL) return;
        maxValue = max(maxValue,root->val);
        rec(root->left,maxValue,count);
        rec(root->right,maxValue,count);
        if(root->val == maxValue) count++;
    }
    int goodNodes(TreeNode* root) {
        int maxValue = INT_MIN;
        int count = 0;
        rec(root,maxValue,count);
        return count;
    }
};