class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles >= numExchange) {
            int canGet = numBottles / numExchange;
            ans += canGet;
            int remaining = numBottles % numExchange;
            numBottles = canGet + remaining;
        }
        return ans;
    }
}