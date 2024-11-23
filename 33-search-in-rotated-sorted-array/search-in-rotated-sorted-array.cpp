class Solution {
public:
    int binary_search(vector<int>& nums, int& target, int low, int high)
    {
        while(low <= high)
        {
            int mid = (low+high) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
     
    int search(vector<int>& nums, int target) {
        int a = 1, b = nums.size();
        if(nums[0] == target) return 0;
        while(a < b && nums[a] >= nums[a-1])
        {
            if(nums[a] == target) return a;
            a++;
        }
        cout<<a;
        return binary_search(nums,target,a,b-1);

    }
};