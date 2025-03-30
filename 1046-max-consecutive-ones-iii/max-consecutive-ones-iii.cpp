class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLength = 0;
        int zeroes = 0;
        int a = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0) zeroes ++;
            while(zeroes > k)
            {
                if(nums[a] == 0) zeroes --;
                a++;
            }
            maxLength = max(maxLength , i - a + 1);
        }
        return maxLength;
    }
};