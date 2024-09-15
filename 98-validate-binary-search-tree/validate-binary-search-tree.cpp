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
    int anc = 0;
    bool leftCheck(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->val >= anc) return false;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return true;
    }

    bool rightCheck(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->val <= anc) return false;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                anc = curr->val;
                if(curr->left) 
                {
                    q.push(curr->left);
                    if(leftCheck(curr->left) == false) return false;
                }
                if(curr->right)
                {
                    q.push(curr->right);
                    if(rightCheck(curr->right) == false) return false;
                }
            }
        }
        return true;
    }
};