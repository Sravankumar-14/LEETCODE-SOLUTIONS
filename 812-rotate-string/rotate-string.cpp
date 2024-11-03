class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            char ch = s[n-1];
            s.pop_back();
            s = ch + s;
            if(s == goal) return true;
        }
        return false;
    }
};