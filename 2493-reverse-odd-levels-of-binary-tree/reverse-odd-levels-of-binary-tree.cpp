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
    void invert(TreeNode* Left, TreeNode* Right , int current)
    {
        if(!Left or !Right) return;
        if(current % 2 == 0)
        {
            int temp = Left->val;
            Left->val = Right->val;
            Right->val = temp;
        }
        invert(Left->left, Right->right,current+1);
        invert(Left->right, Right->left,current+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root -> left and root->right) invert(root->left,root->right,2);
        return root;
    }
};