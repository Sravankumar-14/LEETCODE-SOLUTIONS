class Solution {
public:
    bool isPossible(vector<int>& nums, int val , int k)
    {
        int count = 1;
        long sum = 0;
        for(int i : nums)
        {
            sum += i;
            if(sum > val) 
            {
                sum = i;
                count++;
            }
        }
        return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        long long right = accumulate(nums.begin(),nums.end(),0LL);
        long res = 0;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(isPossible(nums, mid, k))
            {
                res = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return res;
    }
};