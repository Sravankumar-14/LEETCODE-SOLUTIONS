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
    bool pathSum(TreeNode* root, int target, int sum)
    {
        if(!root) return false;
        sum += root->val;
        if(root->left == nullptr and root->right == nullptr) return sum == target;
        return (pathSum(root->left,target,sum) || (pathSum(root->right,target,sum)));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return pathSum(root,targetSum,0);
    }
};