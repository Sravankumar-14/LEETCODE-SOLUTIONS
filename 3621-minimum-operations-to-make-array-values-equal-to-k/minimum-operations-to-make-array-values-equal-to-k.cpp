class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int>st;
        for(int num : nums)
        {
            st.insert(num);
        }
        int size = st.size();
        int count = 0;
        for(int val : st)
        {
            if(val < k) return -1;
            else if (val == k) return size - 1;
            return size;
        }
        return 0;
    }
};