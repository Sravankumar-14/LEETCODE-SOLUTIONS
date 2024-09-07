class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, -1));  // Initialize the matrix with -1
        int a = 1;
        int total = n * n;
        int i = 0, j = 0;
        
        while (a <= total) {
            // Move right
            while (a <= total && j < n) {
                if (ans[i][j] != -1) break;
                ans[i][j++] = a++;
            }
            j--; i++;  // Adjust indices after breaking out
            
            // Move down
            while (a <= total && i < n) {
                if (ans[i][j] != -1) break;
                ans[i++][j] = a++;
            }
            i--; j--;
            
            // Move left
            while (a <= total && j >= 0) {  // Correct the condition here
                if (ans[i][j] != -1) break;
                ans[i][j--] = a++;
            }
            j++; i--;
            
            // Move up
            while (a <= total && i >= 0) {  // Correct the condition here
                if (ans[i][j] != -1) break;
                ans[i--][j] = a++;
            }
            i++; j++;
        }
        
        return ans;
    }
};
