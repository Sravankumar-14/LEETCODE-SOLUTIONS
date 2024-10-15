class Solution {
public:
    long long ceil(long long x)
    {
       if(x%3==0)return x/3;
       return (x/3)+1;
    }
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<int>p;

        for(int i:nums){
            p.push(i);
        }

       long long s=0;
       while(k--)
       {
        s=s+p.top();
        long long x=ceil(p.top());
        p.pop();
        p.push(x);
       }

       return s;

    }
};