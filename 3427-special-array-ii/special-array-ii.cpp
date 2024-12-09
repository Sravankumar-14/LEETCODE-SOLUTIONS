class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>vec(nums.size(),1);
        vector<bool>ans;
        int count = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] % 2 == 0 && nums[i-1] % 2 == 0) {
                count = 1; 
                vec[i] = count;
            }
            else if(nums[i] % 2 != 0 && nums[i-1] % 2 != 0) {
                count = 1;
                vec[i] = count;
            }
            else
            {
                count ++;
                vec[i] = count;
            }
        }
        for(vector<int>& query : queries)
        {
            if(query[1] - query[0] + 1 <= vec[query[1]]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};