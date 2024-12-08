// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long  low = 0;
        long high = n;
        long ans = 0;
        while(low <= high)
        {
            long mid = (low+high)/2;
            if(isBadVersion(mid)) 
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};