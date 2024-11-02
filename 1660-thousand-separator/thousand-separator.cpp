class Solution {
public:
    string thousandSeparator(int n) {
        string str = to_string(n);
        int size = str.size();
        if(size < 4) return str;
        string temp = "";
        int k = 0;
        for(int i=size-1; i>=0; i--)
        {
            if(k != 0 && k%3 == 0) temp += '.';
            temp += str[i];
            k++;
        }
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};