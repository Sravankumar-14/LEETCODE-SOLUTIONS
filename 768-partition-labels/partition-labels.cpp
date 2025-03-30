class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> last;
        vector<int>ans;
        for(int i=0; i<s.size(); i++)
        {
            last[s[i]] = i;
        }
        // for(auto mp : last) cout<<mp.first<<"-"<<mp.second<<endl;
        int it = 0;
        int windowSize = last[s[0]];
        int count = 0;
        while(it < s.size())
        {
            for(; it<=windowSize; it++)
            {
                if(last[s[it]] > windowSize) windowSize = last[s[it]];
                count ++;
            }
            ans.push_back(count);
            count = 0;
            if(it < s.size()) windowSize = last[s[it]];
        }
        return ans;
    }
};