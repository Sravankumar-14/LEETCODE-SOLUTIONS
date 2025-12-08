class Solution {
    public int countTriples(int n) {
        int ans = 0;
        for(int i=n; i>1; i--) {
            HashSet<Integer> set = new HashSet<>();
            for(int j=i-1; j>0; j--) {
                int jSquare = j*j;
                int iSquare = i*i;
                int diff = iSquare - jSquare;
                if(set.contains(diff)) ans += 2;
                set.add(jSquare);
            }
        }
        return ans;
    }
}