class Solution {
public:
    bool isPossible(vector<int>& nums, int val, int& days)
    {
        int count = 1;
        long sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if(sum > val) 
            {
                sum = nums[i];
                count ++;
            }
        }
        return count <= days;
    }
    long long sum(vector<int>& nums)
    {
        long long sum = 0LL;
        for(int i : nums) sum += i;
        return sum;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(),weights.end());
        long long right = sum(weights);
        int res = INT_MAX;
        while(left <= right)
        {
            int mid  = (left + right) / 2;
            if(isPossible(weights,mid,days)){
                res = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return res;
    }
};