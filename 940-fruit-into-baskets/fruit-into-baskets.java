class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> map = new HashMap<>();
        int start = 0;
        int maxFruits = 0;
        for(int i=0; i<fruits.length; i++)
        {
            map.put(fruits[i] , map.getOrDefault(fruits[i],0) + 1);
            while(map.size() > 2 && start < i)
            {
                int count = map.get(fruits[start]);
                if(count > 1) map.put(fruits[start] , count - 1);
                else map.remove(fruits[start]);
                start ++;
            }   
            maxFruits = Math.max(maxFruits , (i - start)+1); 
        }
        return maxFruits;
    }
}