class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 1;
        for(int i=1; i<word.length(); i++)
        {
            if(count == 9)
            {
                comp += '9';
                comp += word[i-1];
                count = 0;
            }
            if(word[i] != word[i-1])
            {
                if(count == 0)
                {
                    count++;
                    continue;
                }
                comp += count + '0';
                count = 1;
                comp += word[i-1];
            }
            else count ++;
        }
        char ch = word[word.size()-1];
        if(count >= 9)
        {
            while(count/9 != 0)
            {
                comp += '9';
                comp += ch;
                count -= 9;
            }
        }
        if(count)
        {
            comp += count + '0';
            comp += ch;
        }
        return comp;
    }
};