class Solution {
    public:
    #define ll long long
    bool calc(ll mid, vector<int>& ranks, int& cars)
    {
        ll total = 0;
        for(int rank : ranks)
        {
            total += sqrt(mid/rank);
        }
        return total >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll low = 1;
        int minValue = *min_element(ranks.begin(),ranks.end());
        ll high = (ll) cars * cars * minValue;
        ll ans = 0;
        while(low <= high)
        {
            ll mid = low +(high - low) / 2;
            if(calc(mid , ranks, cars))
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};