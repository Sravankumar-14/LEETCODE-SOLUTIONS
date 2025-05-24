class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sort(queries.begin(), queries.end());

        int queryPos = 0;
        int usedQueries = 0;
        for(int i=0; i<nums.size(); i++)
        {
            while(queryPos < queries.size() && queries[queryPos][0] == i)
            {
                maxHeap.push(queries[queryPos][1]);
                queryPos ++;
            }
            nums[i] -= minHeap.size();
            while(nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                nums[i] --;
                usedQueries ++;
            }
            if(nums[i] > 0) return -1;
            while(!minHeap.empty() && minHeap.top() == i)
            {
                minHeap.pop();
            }
        }
        return queries.size() - usedQueries;
    }
};