class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int m = num1.size();
        int n = num2.size() + m;
        int row = 0;
        int temp = n;
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=m-1; i>=0; i--)
        {
            int carry = 0;
            int col = n-1;
            for(int j=num2.size()-1; j>=0; j--)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                mul += carry;
                carry = mul / 10;
                ans[row][col--] = mul % 10;
            }
            if(carry) ans[row][col] = carry;
            row ++;
            n--;
        }
        // for(auto row : ans)
        // {
        //     for(int i : row)
        //     {
        //         cout<<i<<" ";
        //     }
        //     cout<<"\n";
        // }
        int c = 0;
        string str = "";
        // cout<<n<<"\n";
        for(int i=temp-1; i>=0; i--)
        {
            int sum = 0;
            for(int j=0; j<m; j++)
            {
                sum += ans[j][i];
            }
            sum += c;
            // cout<<sum<<" ";
            c = sum / 10;
            str += (sum % 10 + '0');
        }
        // cout<<str;
        string t = to_string(c);
        reverse(t.begin(),t.end());
        str += t;
        reverse(str.begin(),str.end());
        int k;
        for(k = 0; k<str.size(); k++) if(str[k] != '0') break;
        return str.substr(k);
    }
};