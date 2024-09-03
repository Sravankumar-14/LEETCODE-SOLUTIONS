class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i : answers)
        {
            if(i == 0)
            {
                ans += 1;
                continue;
            }
            if(mp.find(i) != mp.end())
            {
                mp[i] --;
                if(mp[i] == 0) mp.erase(i);
                continue;
            }
            else 
            {
                mp[i] = i;
                ans += i+1;
            }
        }
        return ans;
    }
};