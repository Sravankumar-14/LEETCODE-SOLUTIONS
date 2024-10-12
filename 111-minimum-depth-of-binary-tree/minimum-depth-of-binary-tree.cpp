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
    int mn = INT_MAX;
    void findMin(TreeNode* root, int val)
    {
        if(root == NULL) return ;
        if(!root->left && !root->right) mn = min(mn, val);
        findMin(root->left,val+1);
        findMin(root->right, val+1);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        findMin(root,1);
        return mn;
    }
};