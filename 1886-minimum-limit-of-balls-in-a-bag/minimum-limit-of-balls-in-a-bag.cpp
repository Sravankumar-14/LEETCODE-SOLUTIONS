class Solution {
public:
    bool canPossible(vector<int>& nums, int val, int total)
    {
        int count = 0;
        for(int i : nums)
        {
            if(i > val)
            {
                count += ceil((double)i/val) - 1;
            }
        }
        return count <= total;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int res = INT_MAX;
        while(low <= high)
        {
            int mid = low + (high-low) / 2;
            if(canPossible(nums,mid,maxOperations))
            {
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};