class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        double totalSum = 0;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++)
        {
            totalSum += skill[i];
            mp[skill[i]] ++;
        }
        double temp = totalSum / (n / 2);
        // if(temp != floor(temp)) return -1;
        // cout<<totalSum<<" "<<temp<<" ";
        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            if(mp.find(temp - skill[i]) != mp.end())
            {
                if(mp[temp-skill[i]] > 0)
                {
                    int t = (temp - skill[i]) * skill[i];
                    ans += t;
                    mp[temp - skill[i]] --;
                    // cout<<t<<" ";
                }
                else return -1;
            }
            else return -1;
        }
        return ans / 2;
    }
};