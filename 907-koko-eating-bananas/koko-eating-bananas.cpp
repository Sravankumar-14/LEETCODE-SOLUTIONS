class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low < high)
        {
            int mid = (low + high )/2;
            if(isItMinimumPiles(piles, h, mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
    bool isItMinimumPiles(vector<int>& piles, int h, int mid)
    {
        if(mid == 0) return true;
        int noOfHours = 0;
        for(int pile : piles)
        {
            noOfHours += (pile % mid == 0) ? pile / mid : pile / mid + 1;
        }
        return (noOfHours <= h) ? true : false;
    }
};