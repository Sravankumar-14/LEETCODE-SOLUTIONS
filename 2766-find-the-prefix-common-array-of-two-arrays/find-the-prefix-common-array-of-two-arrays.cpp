class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int>st;
        vector<int>vec;
        int n = A.size();
        for(int i=0; i<n; i++)
        {
            int count = 0;
            st.insert(A[i]);
            for(int j=0; j<=i; j++)
            {
                if(st.find(B[j]) != st.end())
                {
                    count++;
                }
            }
            vec.push_back(count);
        }
        return vec;
    }
};