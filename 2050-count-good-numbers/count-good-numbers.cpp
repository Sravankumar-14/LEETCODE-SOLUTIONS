class Solution {
public:
    int countGoodNumbers(long long n) {
        long long mod = 1e9 + 7;

        // Calculate number of even and odd positions
        long long evenCount = (n + 1) / 2 ;  // for even length
        long long oddCount = n / 2;  // for odd length
        
        // Use modular exponentiation
        long long result = (power(5, evenCount, mod) * power(4, oddCount, mod)) % mod;
        return (int)result;
    }
    
private:
    long long power(long long base, long long exponent, long long mod) {
        long long result = 1;
        base %= mod;
        
        while (exponent > 0) {
            if (exponent & 1) {  // if exponent is odd
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent >>= 1;  // divide exponent by 2
        }
        return result;
    }
};