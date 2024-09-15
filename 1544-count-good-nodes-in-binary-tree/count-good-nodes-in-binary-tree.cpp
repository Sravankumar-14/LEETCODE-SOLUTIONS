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
    void rec(TreeNode* root,stack<int>&s,int&c)
    {
        if(root==NULL)return ;

        if(s.empty())
        {
            c++;
            s.push(root->val);
            rec(root->left,s,c);
            rec(root->right,s,c);
            s.pop();
        }
        else
        {
           if(s.top()<=root->val)
           {
            c++;
             s.push(root->val);
            rec(root->left,s,c);
            rec(root->right,s,c);
            s.pop();
           }
           else
           {
             rec(root->left,s,c);
            rec(root->right,s,c);
           }
        }
    }
    int goodNodes(TreeNode* root) {
        
        stack<int>s;
        int c=0;
        rec(root,s,c);
        
        return c;
    }
};