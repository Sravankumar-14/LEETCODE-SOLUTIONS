class Solution {
public:
    int findMin(vector<int>& nums) {
        int b = nums.size()-1;
        int a = 0;
        int mn = INT_MAX;
        while(a <= b)
        {
            int mid = (a+b) / 2;
            if(nums[a] <= nums[b])
            {
                mn = min(mn,nums[a]);
                break;
            }
            if(nums[mid] >= nums[a])
            {
                a = mid+1;
                mn = min(mn,nums[a]);
            }
            else
            {
                b = mid-1;
                mn = min(mn,nums[mid]);
            }
        }
        return mn;
    }
};