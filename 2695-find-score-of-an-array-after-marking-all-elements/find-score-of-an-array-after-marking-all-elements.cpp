class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        unordered_map<int,set<int>>mp;
        unordered_set<int>st;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<nums.size(); i++)
        {
            pq.push(nums[i]);
            mp[nums[i]].insert(i);
        }
        
        while(! pq.empty())
        {
            int temp = pq.top();
            if(mp.find(temp) != mp.end())
            {
                if(! mp[temp].empty())
                {
                    int index = *(mp[temp].begin());
                    if(st.find(index) == st.end())
                    {
                        score += temp;
                        if(index > 0) st.insert(index-1);
                        if(index < nums.size()-1) st.insert(index + 1);
                    }
                    mp[temp].erase(mp[temp].begin());
                }
            }
            pq.pop();
        }
        return score;
    }
};