class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        for(int i=1; i<s.size(); i+=2)
        {
            char a = s[i];
            char b = s[i-1];
            if(a != b) ans++;
        }
        return ans;
    }
};