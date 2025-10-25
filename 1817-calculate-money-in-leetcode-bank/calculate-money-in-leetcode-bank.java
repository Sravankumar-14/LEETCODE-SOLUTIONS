class Solution {
    public int totalMoney(int n) {
        int quotient = n / 7;
        int rem = n % 7;
        int ans = 0;
        System.out.println(quotient+" "+ rem);
        for(int i=0; i<=quotient; i++) {
            ans += (28 + (7*i));
        }
        System.out.println(ans);
        int a = 28 + (7*quotient);
        int b = ((rem * (rem + 1)) / 2) + (rem * quotient);
        int trim = a - b;
        System.out.println(trim);
        ans -= trim;
        return ans;
    }
}