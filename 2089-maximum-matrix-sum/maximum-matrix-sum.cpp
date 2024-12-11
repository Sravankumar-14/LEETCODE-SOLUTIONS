class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minusCount = 0;
        long long sum = 0;
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        int count = 0;
        for(auto row : matrix)
        {
            for(auto i : row)
            {
                if(i >= 1) 
                {
                    sum += i;
                    minimum = min(i, minimum);
                }
                else 
                {
                    sum += (i*(-1));
                    maximum = max(i, maximum);
                    count ++;
                }
            }
        }
        // cout<<maximum;
        if(count % 2 != 0)
        {
            if(abs(maximum) > minimum) sum -= (minimum  * 2);
            else sum += (maximum * 2);
        }
        return sum;
    }
};