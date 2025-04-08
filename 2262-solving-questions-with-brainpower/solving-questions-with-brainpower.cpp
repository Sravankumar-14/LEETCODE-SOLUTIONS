class Solution {
public:

    long long maximumPoints(vector<vector<int>>& questions, int index, int size, vector<long long>& dp)
    {
        if(index >= size) return 0;

        if(dp[index] != -1) return dp[index];

        long long exclude = maximumPoints(questions, index + 1, size, dp);
        long long include = maximumPoints(questions, index + questions[index][1] + 1, size, dp) + questions[index][0];

        return dp[index] = max(exclude, include);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int size = questions.size();
        vector<long long>dp(size, -1);
        return maximumPoints(questions, 0, size, dp);
    }
};