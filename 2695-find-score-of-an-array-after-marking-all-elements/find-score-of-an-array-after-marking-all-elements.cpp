class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        vector<pair<int,int>>elements;
        for(int i=0; i<n; i++)
        {
            elements.push_back({nums[i], i});
        }
        sort(elements.begin(), elements.end());
        vector<bool>used(n,false);
        for(auto & [val , idx] : elements)
        {
            if(used[idx]) continue;
            score += val;
            used[idx] = true;
            if(idx > 0) used[idx-1] = true;
            if(idx < n-1) used[idx+1] = true;
        }
        return score;
    }
};