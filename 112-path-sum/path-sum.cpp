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
    bool hasPathSum(TreeNode* root, int target) {
        if(!root) return false;
        queue<TreeNode*>q1;
        queue<int>q2;
        q1.push(root);
        q2.push(root->val);
        // if(root->val == target) return true;
        while(!q1.empty())
        {
            int size = q1.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* curr = q1.front();
                int temp = q2.front();
                q1.pop();
                q2.pop();
                if(!curr->left && !curr->right and temp == target) return true;
                if(curr->left)
                {
                    q1.push(curr->left);
                    q2.push(temp + curr->left->val);
                } 
                if(curr->right)
                {
                    q1.push(curr->right);
                    q2.push(temp + curr->right->val);
                }
            }
        }
        return false;
    }
};