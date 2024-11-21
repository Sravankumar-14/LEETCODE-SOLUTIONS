class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        int a = 0, b = 0;
        while(b < n)
        {
            if(nums[b] == mx) count ++;
            while(count >= k && a <= b)
            {
                ans += (n-b);
                if(nums[a] == mx) count--;
                a++;
            }
            b++;
        }
        return ans;
    }
};