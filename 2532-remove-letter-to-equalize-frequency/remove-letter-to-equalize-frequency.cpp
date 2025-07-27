class Solution {
public:
    bool isValid(map<char,int>mp, char ch)
    {
        mp[ch] --;
        if(mp[ch] == 0) mp.erase(ch);
        int prev = 0;
        bool first = true;
        for(auto m : mp)
        {
            if(first)
            {
                prev = m.second;
                first = false;
            }
            else
            {
                if(prev != m.second) return false;
            }
        }
        return true;
    }
    bool equalFrequency(string word) {
        map<char,int>freq;
        for(char ch : word)
        {
            freq[ch] ++;
        }
        // for(auto f : freq)
        // {
        //     cout<<f.first<<" "<<f.second<<endl;
        // }
        for(auto f : freq)
        {
            if(isValid(freq,f.first))
            {
                return true;
            }
        }
        return false;
    }
};