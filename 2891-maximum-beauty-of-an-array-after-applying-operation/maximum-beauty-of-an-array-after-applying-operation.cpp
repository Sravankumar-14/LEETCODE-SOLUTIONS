class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxLength = 1;
        int b = 0;
        int a = 0;
        while(b < nums.size())
        {
            while(b < nums.size() && nums[b] - nums[a] <= 2*k)
            {
                maxLength =  max(maxLength , b - a + 1);
                b++;
            }
            while(b < nums.size() && a < b && nums[b] - nums[a] > 2*k)
            {
                a++;
            }
        }
        return maxLength;
    }
};