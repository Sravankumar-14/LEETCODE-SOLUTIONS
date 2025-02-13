class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>>minHeap;
        int ans = 0;
        for(int num : nums)
        {
            minHeap.push(num);
        }
        while(minHeap.size() >= 2 && minHeap.top() < k)
        {
            long long first = minHeap.top();
            minHeap.pop();
            long long second = minHeap.top();
            minHeap.pop();
            ans ++;
            long long temp = first * 2LL + second;
            minHeap.push(temp);
        }
        return ans;
    }
};