class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rowZeroes;
        set<int> colZeroes;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    rowZeroes.insert(i);
                    colZeroes.insert(j);
                }
            }
        }

        //replace zeores in rows and columns
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if((rowZeroes.find(i) != rowZeroes.end()) || colZeroes.find(j) != colZeroes.end())
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};