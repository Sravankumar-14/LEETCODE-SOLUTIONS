class Solution {
public:
    int divide(int num)
    {
        if(num % 3 == 0) return num/3;
        return num/3 + 1;
    }
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>p;
        for(int i : nums) p.push(i);
        long long s = 0;
        for(int i=0; i<k; i++)
        {
            s += p.top();
            int x = divide(p.top());
            p.pop();
            p.push(x);
        }
        return s;
    }
};