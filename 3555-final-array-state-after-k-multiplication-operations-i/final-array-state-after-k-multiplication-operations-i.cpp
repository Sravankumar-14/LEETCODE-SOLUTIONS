class Solution {
public:
    int minIndex(vector<int>& nums)
    {
        int index = 0;
        int mini = INT_MAX;
        for(int i=0; i<nums.size(); i++)
        {
            if(mini > nums[i])
            {
                mini = nums[i];
                index = i;
            }
        }
        return index;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i=0; i<k; i++)
        {
            int index = minIndex(nums);
            nums[index] *= multiplier;
        }
        return nums;
    }
};