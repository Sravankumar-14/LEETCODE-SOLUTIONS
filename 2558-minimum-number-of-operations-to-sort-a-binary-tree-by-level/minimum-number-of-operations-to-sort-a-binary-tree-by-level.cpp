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
    // int minSwaps = 0;
    // int partition(vector<int>& vec, int low, int high)
    // {
    //     int l = low;
    //     int pivot = vec[low];
    //     int h = high;
    //     while(l < h)
    //     {
    //         while(l < high && pivot >= vec[l]) l++;
    //         while(h > low && pivot < vec[h]) h--;
    //         if(l < h){
    //             swap(vec[l] , vec[h]);
    //             minSwaps ++;
    //         }
    //     }
    //     if(low != h)
    //     {
    //         swap(vec[low], vec[h]);
    //         minSwaps ++;
    //     }
    //     return h;
    // }

    // void quickSort(vector<int>& vec, int low, int high)
    // {
    //     if(low < high)
    //     {
    //         int j = partition(vec,low,high);
    //         quickSort(vec,low,j-1);
    //         quickSort(vec,j+1,high);
    //     }
    // }
    int findMinSwaps(vector<int>& vec)
    {
        int minSwaps = 0;
       map<int,int>sorted_map;
       int n = vec.size();
       for(int i=0; i<n; i++)
       {
            sorted_map[vec[i]] = i;
       }
       vector<bool>visited(n,false);
       sort(vec.begin(),vec.end());
       int iterator = 0;
       for(auto& [val,idx] : sorted_map)
       {
            if(visited[idx] == true)
            {
                iterator ++;
                continue;
            }
            int len = 1;
            while(idx != iterator)
            {
                idx = sorted_map[vec[idx]];
                visited[idx] = true;
                len++;
            }
            iterator++;
            minSwaps += len-1;
       }
       return minSwaps;
    }
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int>vec;
            // queue<TreeNode*>temp = q;
            // while(!temp.empty())
            // {
            //     vec.push_back(temp.front()->val);
            //     temp.pop();
            // }
            
            for(int i=0; i<size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                vec.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans += findMinSwaps(vec);
        }
        return ans;
    }
};