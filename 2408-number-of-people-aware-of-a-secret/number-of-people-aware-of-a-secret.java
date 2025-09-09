class Solution {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        final int M = 1000000007;
        int ans = 1;
        int curr = 0;

        Queue<int[]> forgetQ = new LinkedList<>();
        Queue<int[]> delayQ = new LinkedList<>();

        forgetQ.add(new int[]{1,1});
        delayQ.add(new int[]{1,1});

        for(int i=1; i<=n; i++) {
            while(!forgetQ.isEmpty() && forgetQ.peek()[0] + forget <= i) {
                int [] front = forgetQ.poll();
                int no = front[1];
                ans = (ans - no + M) % M;
                curr = (curr - no + M) % M;
            }
            while(!delayQ.isEmpty() && delayQ.peek()[0] + delay <= i) {
                int [] front = delayQ.poll();
                curr = (curr + front[1]) % M;
            }

            if(curr > 0) {
                ans = (ans + curr) % M;
                delayQ.add(new int[]{i,curr});
                forgetQ.add(new int[]{i, curr});
            }
        }
        return ans;
    }
}