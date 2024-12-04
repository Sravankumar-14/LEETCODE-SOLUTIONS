class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int aSize = str1.size();
        int bSize = str2.length();
        int a = 0;
        int b = 0;
        while(a < aSize && b < bSize)
        {
            if(str1[a] == str2[b] || str2[b] - str1[a] == 1 || (str2[b] == 'a' && str1[a] == 'z'))
            {
                a++;
                b++;
            } 
            else a++;
        }
        return b == bSize;
    }
};