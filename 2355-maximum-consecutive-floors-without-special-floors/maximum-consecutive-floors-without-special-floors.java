class Solution {
    public int maxConsecutive(int bottom, int top, int[] special) {
        Arrays.sort(special);
        int maxValue = 0;
        if(special[0] - bottom > 0) {
            maxValue = Math.max(maxValue, special[0] - bottom);
        }
        // System.out.println("first" + ans);
        for(int i=1; i<special.length; i++) {
            if(special[i] - special[i-1] > 1) {
                maxValue = Math.max(maxValue, special[i] - special[i-1] - 1);
            }
            // System.out.println("special" + special[i] + "-" + special[i-1] + "=" + ans);
        }
        if(top - special[special.length-1] > 0) {
            maxValue = Math.max(maxValue, top - special[special.length-1]);
        }
        // System.out.println("last" + ans);
        return maxValue;
    }
}