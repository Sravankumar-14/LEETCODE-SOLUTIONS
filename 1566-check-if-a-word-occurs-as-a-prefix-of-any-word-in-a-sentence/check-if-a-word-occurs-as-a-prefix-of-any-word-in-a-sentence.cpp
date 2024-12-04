class Solution {
public:
    bool isTrue(string str1, string str2)
    {
        int a = 0;
        for(char ch : str2)
        {
            if(ch != str1[a++]) return false;
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans = 1;
        string str = "";
        for(char ch : sentence)
        {
            if(ch != ' ')
            {
                str += ch;   
            }
            else
            {
                if(isTrue(str, searchWord)) return ans;
                str = "";
                ans ++;
            }
        }
        if(isTrue(str,searchWord)) return ans;
        return -1;
    }
};