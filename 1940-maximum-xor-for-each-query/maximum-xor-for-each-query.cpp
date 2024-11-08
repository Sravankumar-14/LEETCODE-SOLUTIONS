class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mb) {
        int n = nums.size();
        vector<int>ans;
        vector<int>prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            prefix[i] = prefix[i-1] ^ nums[i];
        }
        for(int j=0; j<n; j++)
        {
            int num = prefix[j];
            int temp = 0;
            int i = 0;
            int b = mb;
            
            while(b)
            {
                if((num & 1) == 0) temp += 1<<i;
                i++;
                num = num >> 1;
                b --;
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};