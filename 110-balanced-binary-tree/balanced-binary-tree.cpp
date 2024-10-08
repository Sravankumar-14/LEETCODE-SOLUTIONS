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
    bool istrue = true;    
    int check(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = check(root->left);
        int right = check(root->right);
        int temp = abs(left - right);
        if(temp > 1 && istrue)
        {
            istrue = false;
        }
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        check(root);
        return istrue;
    }
};