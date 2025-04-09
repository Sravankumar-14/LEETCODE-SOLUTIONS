class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>st;
        for(int num : nums)
        {
            if(num < k) return -1;
            st.insert(num);
        }
        if(st.find(k) != st.end()) return st.size()-1;
        return st.size();
    }
};