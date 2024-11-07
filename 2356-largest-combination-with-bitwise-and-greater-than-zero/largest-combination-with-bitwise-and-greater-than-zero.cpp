class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        vector<vector<int>>vec(n,vector<int>(24,0));
        int maxBound = 0;
        for(int i=0; i<n; i++)
        {
            int bound = 0;
            int num = candidates[i];
            int j = 0;
            while(num)
            {
                if((num & 1) == 1)vec[i][j] = 1;
                num = num >> 1;
                j++;
                bound ++;
            }
            maxBound = max(bound , maxBound);
        }
        int maxValue = 0;
        for(int i=0; i<maxBound; i++)
        {
            int value = 0;
            for(int j=0; j<n; j++)
            {
                if(vec[j][i] == 1) value ++;
            }
            maxValue = max(value,maxValue);
        }
        return maxValue;
    }
};