class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int current = numBottles;
        while(current >= numExchange) {
            current -= numExchange;
            numExchange ++;
            ans ++;
            current ++;
        }
        return ans;
    }
}