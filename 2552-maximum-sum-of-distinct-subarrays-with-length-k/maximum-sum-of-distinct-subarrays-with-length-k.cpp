class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        long long maxSum = 0;
        long long sum = 0;
        for(int i=0; i<k; i++)
        {
            sum += nums[i];
            mp[nums[i]] ++;
        }
        int a = 0;
        for(int i=k; i<nums.size(); i++)
        {
            if(mp.size() == k)
            {
                maxSum = max(maxSum , sum);
            }
            mp[nums[a]] --;
            if(mp[nums[a]] == 0) mp.erase(nums[a]);
            sum -= nums[a];
            a++;
            sum += nums[i];
            mp[nums[i]] ++;
        }
        if(mp.size() == k) maxSum = max(sum,maxSum);
        return maxSum;
    }
};