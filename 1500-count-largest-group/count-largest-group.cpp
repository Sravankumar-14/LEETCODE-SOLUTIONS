class Solution {
public:

    int sumOfDigits(int num)
    {
        int sum = 0;
        while(num)
        {
            int rem = num % 10;
            sum += rem;
            num /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        map<int,int>mp;
        for(int i=1; i<=n; i++)
        {
            int sum = sumOfDigits(i);
            mp[sum] ++;
        }
        int size = 1;
        int groups = 0;
        for(auto m : mp)
        {
            cout<<m.first<<" "<<m.second<<endl;
            if(m.second > size)
            {
                size = m.second;
                groups = 0;
            }
            if(m.second == size) groups ++;
        }
        return groups;
    }
};