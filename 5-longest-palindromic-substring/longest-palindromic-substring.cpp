class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        string str = s.substr(0,1); // Initialize with the first character
        int maxi = 1;

        // Substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            matrix[i][i] = 1;
        }

        // Check substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                matrix[i][i + 1] = 1;
                if (maxi < 2) {
                    maxi = 2;
                    str = s.substr(i, 2);
                }
            }
        }

        // Check substrings of length > 2
        for (int len = 3; len <= n; len++) {
            for (int a = 0; a <= n - len; a++) {
                int b = a + len - 1;
                if (s[a] == s[b] && matrix[a + 1][b - 1] == 1) {
                    matrix[a][b] = 1;
                    if (maxi < len) {
                        maxi = len;
                        str = s.substr(a, len);
                    }
                }
            }
        }

        return str;
    }
};
