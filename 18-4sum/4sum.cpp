class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int k = j+1;
                int l = n-1;
                while(k < l)
                {
                    long long sum = (long long) nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == target)
                    {
                        vector<int>row;
                        row.push_back(nums[i]);
                        row.push_back(nums[j]);
                        row.push_back(nums[k]);
                        row.push_back(nums[l]);
                        result.push_back(row);
                        k++;
                        l--;
                        while(k < n && nums[k] == nums[k-1]) k++;
                        while(l >=0 && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum > target) l--;
                    else k++;
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return result;
    }
};