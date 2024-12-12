class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int gift : gifts) pq.push(gift);
        long long ans = 0;
        for(int i=0; i<k; i++)
        {
            int temp = pq.top();
            temp = floor(sqrt(temp));
            pq.pop();
            pq.push(temp);
        }
        while(pq.size() > 0)
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};