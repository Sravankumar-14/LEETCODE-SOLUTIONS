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
    bool istrue ;
    bool confirm = false;
    void isSame(TreeNode* root, TreeNode* subRoot)
    {
        if(!root && !subRoot) return;
        if(!root || !subRoot) 
        {
            istrue = false;
            return;
        }
        if(root->val != subRoot->val) istrue = false;
        isSame(root->left,subRoot->left);
        isSame(root->right,subRoot->right);
    }
    void findRoot(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL) return;
        if(root->val == subRoot->val) 
        {
            istrue = true;
            isSame(root,subRoot);
            if(istrue) confirm = true;
        }
        findRoot(root->left,subRoot);
        findRoot(root->right,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        findRoot(root,subRoot);
        return confirm;
    }
};