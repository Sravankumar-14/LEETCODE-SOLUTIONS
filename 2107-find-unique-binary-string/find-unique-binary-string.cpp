class Solution {
public:
    string convertToBinary(int num, int size)
    {
        string str = "";
        for(int i=0; i<size; i++)
        {
            str.push_back('0');
        }
        string str1 = "";
        while(num)
        {
            int rem = num % 2;
            str1 += ('0' + rem);
            num /= 2;
        }
        for(int i=0; i<str1.size(); i++)
        {
            str[i] = str1[i];
        }
        reverse(str.begin(), str.end());
        return str;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int size = nums.size();
        unordered_set<string>st;
        for(string str : nums)
        {
            st.insert(str);
        }
        for(int i=0; i<pow(2,size); i++)
        {
            string str = convertToBinary(i,size);
            if(st.find(str) == st.end())
            return str;
        }
        return "";
    }
};