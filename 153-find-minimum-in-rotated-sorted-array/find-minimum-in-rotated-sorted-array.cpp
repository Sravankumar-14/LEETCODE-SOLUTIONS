class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int minElement = nums[n-1];
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] > minElement) return minElement;
            minElement = nums[i];
        }
        return minElement;
    }
};