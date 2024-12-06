class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>st;
        for(int i : banned) st.insert(i);
        int ans = 0;
        int count = 0;
        for(int i=1; i<= n; i++)
        {
            if(st.find(i) == st.end())
            {
                ans += i;
                if(ans <= maxSum) count++;
                else return count;
            }
            
        }
        return count;
    }
};