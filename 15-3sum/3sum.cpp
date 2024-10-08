class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0)
                {
                    vector<int>row;
                    row.push_back(nums[i]);
                    row.push_back(nums[j]);
                    row.push_back(nums[k]);
                    result.push_back(row);
                    j++;
                    k--;
                    while(j < n && nums[j] == nums[j-1]) j++;
                    while(k >=0 && nums[k] == nums[k+1]) k--;
                }
                else if(sum > 0) k--;
                else j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return result;
    }
};