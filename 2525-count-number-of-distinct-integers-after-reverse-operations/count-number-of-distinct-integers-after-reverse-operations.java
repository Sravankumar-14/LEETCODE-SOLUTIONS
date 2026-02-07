class Solution {

    public int reverse(int num) {
        int val = 0;
        while(num != 0) {
            int rem = num % 10;
            num /= 10;
            val *= 10;
            val += rem;
        }
        return val;
    }

    public int countDistinctIntegers(int[] nums) {
        int numsSize = nums.length;
        int [] newArray = new int[numsSize*2];
        for(int i=0; i<numsSize; i++) {
            newArray[i] = nums[i];
        }

        for(int i=0; i<nums.length; i++) {
            newArray[i+numsSize] = reverse(nums[i]);
        }

        // for(int num : newArray) {
        //     System.out.println(num);
        // }

        int[] unique = Arrays.stream(newArray).distinct().toArray();
        return unique.length;
    }
}