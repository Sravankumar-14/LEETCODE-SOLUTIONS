class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxValue = 0;
        unordered_set<string>st;
        for(int i=0; i<arr1.size(); i++)
        {
            string str = to_string(arr1[i]);
            string str1 = "";
            for(int j=0; j<str.size(); j++)
            {
                str1 += str[j];
                st.insert(str1);
            }
        }
        for(int i=0; i<arr2.size(); i++)
        {
            string str = to_string(arr2[i]);
            string str1 = "";
            for(int j=0; j<str.size(); j++)
            {
                str1 += str[j];
                if(st.find(str1) != st.end())
                {
                    maxValue = max(maxValue, static_cast<int>(str1.size()));
                } 
            }  
        }
        return maxValue;
    }
};