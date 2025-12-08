class Solution {
    public int countTriples(int n) {
        int ans = 0;
        for(int i=n; i>2; i--) {
            for(int j=i-1; j>1; j--) {
                for(int k=j-1; k>0; k--) {
                    int squareSum = (k*k) + (j*j);
                    if(squareSum == (i*i)) ans++;
                }
            }
        }
        return ans*2;
    }
}