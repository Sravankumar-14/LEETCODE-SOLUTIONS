class Solution {
public:
    string rle(string str)
    {
        int n = str.size();
        int freq = 1;
        string res = "";
        for(int i=1; i<n; i++)
        {
            if(str[i] == str[i-1])
            {
                freq ++;
                continue;
            }
            res += (freq + '0') ;
            res += str[i-1];
            freq = 1;
        }
        res += (freq + '0');
        res += str[n-1];
        return res;
    }
    string countAndSay(int n) {
        string res = "1";
        for(int i=1; i<n; i++)
        {
            res = rle(res);
        }
        return res;
    }
};