class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if(sum < 0) sum = 0;
            maxSum = max(maxSum , sum);
        }
        for(int i=0; i<nums.size(); i++)
        {
            nums[i] *= -1;
        }
        sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if(sum < 0) sum = 0;
            maxSum = max(maxSum , sum);
        }
        return maxSum;
    }
};