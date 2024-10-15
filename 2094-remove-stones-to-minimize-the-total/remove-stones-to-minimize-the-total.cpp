class Solution {
public:
    int divide(int num)
    {
        // if(num % 2 == 0) return num/2;
        cout<<num/2<<" ";
        return num - num/2;
    }
    int minStoneSum(vector<int>& nums, int k) {
        priority_queue<int>p;
        for(int i : nums) p.push(i);
        long long s = 0;
        for(int i=0; i<k; i++)
        {
            // s += p.top();
            int x = divide(p.top());
            p.pop();
            p.push(x);
        }
        while(!p.empty())
        {
            s += p.top();
            p.pop();
        }
        return s;
    }
};