class Solution {

    boolean isPossible(int[] batteries, long time, int n) {
        long totalTime = 0;
        for(int battery : batteries) {
            if(battery < time) totalTime += battery;
            else totalTime += time;
        }
        return (totalTime >= (n * time));
    }

    public long maxRunTime(int n, int[] batteries) {
        long low = 0;
        long high = 0;
        for(int num : batteries) high += num;

        long ans = 0;
        while(low <= high) {
            long mid = low + (high - low) / 2;
            if(isPossible(batteries, mid, n)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
}