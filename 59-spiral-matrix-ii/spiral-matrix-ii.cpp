class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,-1));
        int a = 1;
        int total = n*n;
        int i=0,j=0;
        while(a<=total)
        {
            while(a<=total && j<n)
            {
                if(ans[i][j] != -1) break;
                ans[i][j++] = a++;
            }
            j--;
            i++;
            while(a<=total && i<n)
            {
                if(ans[i][j] != -1) break;
                ans[i++][j] = a++;
            }
            i--;
            j--;
            while(a<=total && j>=0)
            {
               if(ans[i][j] != -1) break;
                ans[i][j--] = a++;
            }
            j++;
            i--;
            while(a<=total && i>=0)
            {
                if(ans[i][j] != -1) break;
                ans[i--][j] = a++;
            }
            i++;
            j++;
        }
        return ans;
    }
};