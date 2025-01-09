class Solution {
    public int checkLeft(String boxes, int index)
    {
        int sum = 0;
        for(int i=0; i<index; i++)
        {
            if(boxes.charAt(i) == '1') sum += index-i;
        }
        return sum;
    }
    public static int checkRight(String boxes, int index)
    {
        int sum = 0;
        for(int i=index+1; i<boxes.length(); i++)
        {
           if(boxes.charAt(i) == '1') sum += i - index;
        }
        return sum;
    }
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int [] arr = new int[n];
        for(int i=0; i<n; i++)
        {
            arr[i] = checkLeft(boxes, i) + checkRight(boxes, i);
        }
        return arr;
    }
}