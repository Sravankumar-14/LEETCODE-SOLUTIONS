class Solution {
public:

    bool isSymmetric(int num)
    {
        string str = to_string(num);
        if(str.size() % 2 == 1) return false;
        int sub1 = 0;
        int sub2 = 0;
        for(int i=0; i<str.size()/2; i++)
        {
            sub1 += (str[i] - '0');
        }
        for(int i=str.size()/2; i<str.size(); i++)
        {
            sub2 += (str[i] - '0');
        }
        return sub1 == sub2;

    }

    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i=low; i<=high; i++)
        {
            if(isSymmetric(i)) ans++;
        }
        return ans;
    }
};