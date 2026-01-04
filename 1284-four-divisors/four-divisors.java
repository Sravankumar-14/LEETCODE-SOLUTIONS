class Solution {
    public int sumFourDivisors(int[] nums) {
        int total = 0;
        for(int num : nums) {
            int count = 0;
            int sum = 0;
            for(int i=1; i*i <= num; i++) {
                if(num % i == 0) {
                    sum += i;
                    count ++;
                    if(i != num/i) {
                        sum += (num / i);
                        count ++;
                    }
                }
                if(count > 4) break;
            }
            if(count == 4) total += sum;
        }
        return total;
    }
}