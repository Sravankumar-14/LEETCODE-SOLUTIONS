class Solution {
public:
    int addMinimum(string word) {
        string str = "abc";
        int i = 0;
        int j = 0;
        int count = 0;
        while(j < word.size())
        {
            if(word[j] == str[i%3]) 
            {
                i++;
                j++;
            }
            else
            {
                count ++;
                i++;
            }
        }
        for(int k=0; (i++%3) != 0 ; k++) count++;
        return count;
    }
};