class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        vector<int>suffix(n);
        suffix[n-1] = shifts[n-1];
        for(int i=n-2; i>=0; i--)
        {
            suffix[i] = (suffix[i+1] + shifts[i]) % 26;
        }
        for(int i=0; i<suffix.size(); i++)
        {
                int t = (s[i] - 'a') % 26;
                int temp = (t+suffix[i]) % 26;
                // if(temp == 25) s[j] = 'a';
                s[i] = 'a' + temp;
            
        }
        return s;
    }
};