class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isItMaxPile(candies, k, mid))
                low = mid + 1;
            else
                high = mid;
        }
        
        return (isItMaxPile(candies, k, low)) ? low : low - 1;
    }

    bool isItMaxPile(vector<int>& candies, long long k, int mid) {
        if (mid == 0) return true;
        long long children = 0;
        for (int candy : candies) {
            children += candy / mid;
            if (children >= k) return true;
        }
        return false;
    }
};
