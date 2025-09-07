class Solution {
    public int[] sumZero(int n) {
        int[] ans = new int[n];
        int start = (n/2) * -1;
        int end = (n/2);
        int index = 0;
        for(int i=start; i<=end; i++) {
            if(i == 0) continue;
            ans[index++] = i;
        }
        if(n%2 != 0) ans[index] = 0;
        return ans;
    }
}