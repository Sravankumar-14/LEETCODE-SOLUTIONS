class Solution {

    boolean anyOdds(int [] nums1) {
        for(int i=0; i<nums1.length; i++) {
            if(nums1[i] % 2 != 0) return true;
        }
        return false;
    }

    public boolean uniformArray(int[] nums1) {
        Arrays.sort(nums1);
        if(nums1[0] % 2 != 0) return true;
        boolean anyOdds = anyOdds(nums1);
        return !anyOdds;
    }
}