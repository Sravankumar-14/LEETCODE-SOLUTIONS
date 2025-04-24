class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0;
        set<int>distinctElements;
        for(int num : nums)
        {
            distinctElements.insert(num);
        }
        int distinct = distinctElements.size();
        for(int i=0; i<nums.size(); i++)
        {
            set<int>st;
            for(int j=i; j<nums.size(); j++)
            {
                st.insert(nums[j]);
                if(st.size() == distinct) ans++;
            }
        }
        return ans;
    }
};