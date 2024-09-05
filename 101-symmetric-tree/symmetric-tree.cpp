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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int>temp;
            for(int i=0; i<size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) temp.push_back(curr->left->val);
                else temp.push_back(101);
                if(curr->right) temp.push_back(curr->right->val);
                else temp.push_back(101);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            int a = 0;
            int n = temp.size()-1;
            while(a < n)
            {
                if(temp[a] != temp[n]) return false;
                a++;
                n--;
            }
        }
        return true;
    }
};