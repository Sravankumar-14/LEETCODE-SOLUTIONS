class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int length = nums.length;
        int [] maxArray = new int [length];
        int [] minArray = new int [length];

        int prevMax = nums[0];
        maxArray[0] = prevMax;
        for(int i=1; i<length; i++) {
            maxArray[i] = Math.max(prevMax, nums[i]);
            prevMax = maxArray[i];
        }

        int prevMin = nums[length-1];
        minArray[length-1] = prevMin;
        for(int i=length-2; i>=0; i--) {
            minArray[i] = Math.min(prevMin, nums[i]);
            prevMin = minArray[i];
        }

        for(int i=0; i<length; i++) {
            // System.out.println(maxArray[i] + " " + minArray[i]);
            int diff = maxArray[i] - minArray[i];
            if (diff <= k) return i;
        }
        return -1;
    }
}