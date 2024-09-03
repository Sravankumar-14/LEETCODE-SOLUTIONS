class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<int>ans;
        int a = 0;
        if(n%2 == 0) a = n/2-1;
        else a = n/2;
        int b = n-1;
        for(int i=0; i<n/2; i++)
        {
            ans.push_back(nums[a--]);
            ans.push_back(nums[b--]);
        }
        if(a >= 0) ans.push_back(nums[0]);
        nums = ans;
        
    }
};