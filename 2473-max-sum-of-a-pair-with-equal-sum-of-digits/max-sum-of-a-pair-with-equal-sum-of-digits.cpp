class Solution {
public:
    int sumOfDigits(int num)
    {
        int sum = 0;
        while(num)
        {
            int rem = num % 10;
            num /= 10;
            sum += rem;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>>mp;
        for(int num : nums)
        {
            int sum = sumOfDigits(num);
            mp[sum].push(num);
        }
        int maxValue = -1;
        for(auto m : mp)
        {
            int value = 0;
            if(m.second.size() >= 2)
            {
                value += m.second.top();
                m.second.pop();
                value += m.second.top();
                maxValue = max(maxValue , value);
            }
        }
        return maxValue;
    }
};