class Solution {
    public :
    string addSpaces(string s, vector<int>& spaces) {
        int prev = 0;
        string str = "";
        for(int i : spaces)
        {
            str += s.substr(prev,i-prev);
            str += " ";
            prev = i;
        }
        str += s.substr(prev);
        return str;
    }
};