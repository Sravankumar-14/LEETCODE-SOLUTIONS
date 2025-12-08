class Solution {
    public int countTriples(int n) {
        int ans = 0;
        for(int i=n-1; i>1; i--) {
            // HashSet<Integer> set = new HashSet<>();
            for(int j=i-1; j>0; j--) {
                int jSquare = j*j;
                int iSquare = i*i;
                int res = (int) Math.sqrt(jSquare + iSquare);
                // if(set.contains(diff)) ans += 2;
                // set.add(jSquare);
                if(res * res == iSquare + jSquare && res <= n) ans += 2;
            }
        }
        return ans;
    }
}