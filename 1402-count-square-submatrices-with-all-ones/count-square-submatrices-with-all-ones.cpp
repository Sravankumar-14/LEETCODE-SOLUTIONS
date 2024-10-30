class Solution {
public:
    int minValue(int a, int b, int c)
    {
        return min(a, min(b,c));
    }
    int countSquares(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int sum = 0;
        vector<vector<int>>vec(rowSize, vector<int>(colSize,0));
        for(int i=0; i<colSize; i++)
        {
            vec[0][i] = matrix[0][i];
            sum += vec[0][i];
        }
        for(int i=1; i<rowSize; i++)
        {
            vec[i][0] = matrix[i][0];
            sum += vec[i][0];
        }
        for(int i=1; i<rowSize; i++)
        {
            for(int j=1; j<colSize; j++)
            {
                if(matrix[i][j] == 1)
                vec[i][j] = minValue(vec[i-1][j-1] , vec[i][j-1], vec[i-1][j]) + 1;
                sum += vec[i][j];
            }
        }
        return sum;
    }
};