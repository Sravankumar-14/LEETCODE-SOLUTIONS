class Solution {
    public int binaryGap(int n) {
        int startPos = 1;
        int endPos = 1;
        int maxValue = 0;
        int index = 1;
        while(n != 0) {
            int curr = (n & 1);
            n >>= 1;
            if(curr == 1) {
                startPos = index ++;
                break;
            }
        }
        // System.out.println("startPos = " + startPos + " and curr index is " + index);

        while(n != 0) {
            int curr = (n & 1);
            n >>= 1;
            if(curr == 1) {
                endPos = index;
                maxValue = Math.max(maxValue, (endPos - startPos));
                startPos = endPos;
            }
            index++;
        }

        return maxValue;

    }
}