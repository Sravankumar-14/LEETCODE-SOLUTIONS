class Solution {
public:
    int maxValue(string str)
    {
        int value = 0;
        for(int i=0; i<str.length(); i++)
        {
            value += (str[i] - '0') * pow(2,str.length()-1-i);
        }
        return value;
    }
    string convert(int num)
    {
        if(num == 0) return "0";
        string str = "";
        while(num != 0)
        {
            int temp = num % 2;
            str += temp + '0';
            num /= 2;
        }
        reverse(str.begin(), str.end());
        return str;
    }
    int maxGoodNumber(vector<int>& nums) {
        string a = convert(nums[0]);
        string b = convert(nums[1]);
        string c = convert(nums[2]);
        return max({
            maxValue(a+b+c),
            maxValue(a+c+b),
            maxValue(b+a+c),
            maxValue(b+c+a),
            maxValue(c+a+b),
            maxValue(c+b+a)
        });
    }
};