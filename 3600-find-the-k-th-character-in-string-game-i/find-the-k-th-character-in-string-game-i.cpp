class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";
        while(str.length() < k)
        {
            int n = str.size();
            cout<<str<<" ";
            for(int i=0; i<n; i++)
            {
                if(str[i] == 'z') str += 'a';
                else str += (char)(str[i]+1);
            }
        }
        return str[k-1];
    }
};