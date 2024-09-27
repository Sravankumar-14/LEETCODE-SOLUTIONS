class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int>ans(2);
        int mini = INT_MAX;
        for(int i=1; i<=area; i++)
        {
            if(area % i != 0) continue;
            int l = i;
            int w = area / l;
            if(l < w) continue;
            int diff = abs(l-w);
            if(mini > diff)
            {
                mini = diff;
                ans[0] = l;
                ans[1] = w;
            }
        }
        return ans;
    }
};