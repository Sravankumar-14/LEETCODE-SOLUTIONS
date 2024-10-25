class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>store(128,-1);
        int start = 0;
        int maxValue = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(store[s[i]] >= start)
            start = store[s[i]] + 1;
            store[s[i]] = i;
            maxValue = max(maxValue, i - start + 1);
        }
        return maxValue;
    }
};