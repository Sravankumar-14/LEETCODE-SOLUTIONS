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
    int maxHeight(TreeNode* root)
    {
        if(root == NULL) return 0;
        return max(maxHeight(root->left) , maxHeight(root->right)) + 1;
    }

    void buildVector(TreeNode* root, vector<int>& vec, int level)
    {
        if(root == NULL) return;
        buildVector(root->left, vec, level+1);
        buildVector(root->right, vec, level+1);
        vec[level] = max(vec[level] , root->val);
    }

public:
    vector<int> largestValues(TreeNode* root) {
        int n = maxHeight(root);
        vector<int>vec(n,INT_MIN);
        buildVector(root,vec,0);
        return vec;
    }
};