class Solution {
    public int[] findEvenNumbers(int[] digits) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int num : digits)
        {
            map.put(num, map.getOrDefault(num,0)+1);
        }

        ArrayList<Integer>list = new ArrayList<>();
        for(int i=100; i<1000; i+=2)
        {
            HashMap<Integer,Integer> mp = new HashMap<>();
            int num = i;
            while(num > 0)
            {
                int rem = num % 10;
                mp.put(rem, mp.getOrDefault(rem,0) + 1);
                num /= 10;
            }
            boolean isOk = true;
            for(Integer key : mp.keySet())
            {
                int freq = mp.get(key);
                if (!map.containsKey(key) || map.get(key) < freq)
                {
                    isOk = false;
                    break;
                }
            }
            if(isOk) list.add(i);
        }
        int [] ans = new int[list.size()];
        for(int i=0; i<list.size(); i++)
        {
            ans[i] = list.get(i);
        }
        return ans;
    }
}