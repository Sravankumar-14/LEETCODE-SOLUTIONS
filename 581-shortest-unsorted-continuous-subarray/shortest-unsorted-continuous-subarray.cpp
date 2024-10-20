class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int temp = n;
        vector<int>check = nums;
        sort(check.begin(),check.end());
        for(int i=0; i<n; i++)
        {
            if(check[i] == nums[i]) temp--;
            else break;
        }
        if(temp == 0) return temp;
        for(int i=n-1; i>=0; i--)
        {
            if(check[i] == nums[i]) temp--;
            else break;
        }
        return temp;
    }
};