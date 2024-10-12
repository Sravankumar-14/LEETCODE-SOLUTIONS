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
    void preorder(TreeNode* root, bool& flag, int num)
    {
        if(root == NULL) return;
        if(root->val != num) flag = false;
        preorder(root->left,flag,num);
        preorder(root->right,flag,num);
    }
    bool isUnivalTree(TreeNode* root) {
        bool flag = true;
        preorder(root,flag,root->val);
        return flag;
    }
};