class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int i : nums)
        {
            st.insert(i);
        }
        int maxLen = 0;
        for(int i: nums)
        {
            int len = 0;
            long long present = i;
            for(int j=0; j<5; j++)
            {
                if(st.find(present) != st.end())
                {
                    len ++;
                    if(present * present > 100000) break;
                    present *= present; 
                    
                }
                // else break;
            }
            maxLen = max(maxLen , len);
        }
        return (maxLen > 1) ? maxLen : -1;
    }
};