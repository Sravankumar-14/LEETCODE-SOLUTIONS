class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);
        int a = 0;
        int b = 0;
        int n = players.length;
        int m = trainers.length;
        int ans = 0;
        while(a < n && b < m)
        {
            if(players[a] <= trainers[b])
            {
                ans++;
                a++;
                b++;
            } 
            else b++;
        }
        return ans;
    }
}