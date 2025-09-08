class Solution {

    boolean isContainsZero(int num) {
        while(num != 0) {
            int rem = num % 10;
            if(rem == 0) return true;
            num /= 10;
        }
        return false;
    }

    public int[] getNoZeroIntegers(int n) {
        int b = 0;
        int [] ans = new int[2];
        while(true) {
            b++;
            if(!isContainsZero(n-b) && !isContainsZero(b)) {
                ans[0] = (n-b);
                ans[1] = b;
                break;
            }
        }
        return ans;
    }
}