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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*>q;
        int ans = 1;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left == NULL && curr->right == NULL) return ans;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans++;
        }
        return 0;
    }
};