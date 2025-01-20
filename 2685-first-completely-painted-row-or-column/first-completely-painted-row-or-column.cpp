class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int,int>> mp;
        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat[0].size(); j++)
            {
                mp[mat[i][j]] = {i,j};
            }
        }
        int rowSize = mat.size();
        int colSize = mat[0].size();
        vector<int>rows(rowSize);
        vector<int>cols(colSize);
        for(int i=0; i<arr.size(); i++)
        {
            int row = mp[arr[i]].first;
            int col = mp[arr[i]].second;
            rows[row]++;
            cols[col]++;
            if(rows[row] == colSize || cols[col] == rowSize) return i;
        }
        return 0;
    }
};