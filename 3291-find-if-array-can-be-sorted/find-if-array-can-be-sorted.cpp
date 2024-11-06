class Solution {
public:
    int setBits(int num)
    {
        int count = 0;
        while(num)
        {
            if(num & 1 == 1) count++;
            num = num >> 1;
        }
        return count;
    }
    bool canSortArray(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int prev = 0;
        vector<int>setB(nums.size());
        for(int i=0; i<nums.size(); i++) {
            setB[i] = setBits(nums[i]);
            // cout<<setB[i]<<" ";
        }
        for(int i=1; i<nums.size(); i++)
        {
            if(setB[i] == setB[i-1])
            {
                mini = min(mini,nums[i]);
                maxi = max(maxi,nums[i]);
            }
            else
            {
                if(prev > mini) return false;
                prev = maxi;
                mini = nums[i];
                maxi = nums[i];
            }
        }
        if(prev > mini) return false;
        return true;
    }
};