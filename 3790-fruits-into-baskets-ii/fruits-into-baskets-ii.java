class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int size = fruits.length;
        int [] visited = new int[size];
        int ans = 0;
        for(int i=0; i<size; i++)
        {
            boolean flag = false;
            for(int j=0; j<size; j++)
            {
                if(visited[j] != 1 && fruits[i] <= baskets[j])
                {
                    visited[j] = 1;
                    flag = true;
                    break;
                }
            }
            if(!flag) ans++;
        }
        return ans;
    }
}