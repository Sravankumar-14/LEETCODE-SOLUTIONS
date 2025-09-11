class Solution {

    public int[] getNextMaximum(int[] nums, int index, int size) {
        int [] ans = new int[2];
        int presentMax = Integer.MAX_VALUE;
        int value = nums[index];
        int place = Integer.MAX_VALUE;
        for(int i=index; i<size; i++) {
            if(nums[i] > value && nums[i] < presentMax){
                presentMax = nums[i];
                place = i;
            }
        }
        ans[0] = presentMax;
        ans[1] = place;
        return ans;
    }

    public void nextPermutation(int[] nums) {
       boolean isTotalDesc = true;
       int size = nums.length;

       for(int i=size-1; i>=0; i--) {
        int [] result = getNextMaximum(nums,i,size);
        if(result[0] != Integer.MAX_VALUE) {
            //swaping 
            int temp = nums[i];
            nums[i] = nums[result[1]];
            nums[result[1]] = temp;
            // for(int num : nums) System.out.println(num);
            Arrays.sort(nums,i+1,size);
            isTotalDesc = false;
            break;
        } //else{
        //     System.out.println("no re");
        // }
       } 
       if(isTotalDesc) {
        int a = 0;
        int b = size-1;
        while(a < b) {
            int temp = nums[a];
            nums[a] = nums[b];
            nums[b] = temp;
            a++;
            b--;
        }
       }
    }
}