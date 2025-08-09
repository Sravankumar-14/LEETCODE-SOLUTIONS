class Solution {
public:
    vector<int> segTree;

    void buildSegmentTree(vector<int>&baskets, int low, int high, int index)
    {
        if(low == high)
        {
            segTree[index] = baskets[low];
            return;
        }
        int mid = low + (high - low) / 2;
        buildSegmentTree(baskets,low,mid,index*2);
        buildSegmentTree(baskets,mid+1,high,index*2+1);
        segTree[index] = max(segTree[index*2], segTree[index*2+1]);
    }

    int findLeftMostBasket(int fruit, int low, int high, int index)
    {
        if(segTree[index] < fruit) return -1;
        if(low == high)
        {
            segTree[index] = -1;
            return 1;
        }
        int mid = low + (high - low) / 2;
        int val;
        if(segTree[2*index] >= fruit) val = findLeftMostBasket(fruit,low,mid,index*2);
        else                          val = findLeftMostBasket(fruit,mid+1,high,index*2+1);
        segTree[index] = max(segTree[2*index] , segTree[2*index+1]);
        return val;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        segTree = vector<int>(4*n+1);

        int sg_idx = 1;
        buildSegmentTree(baskets,0,n-1,sg_idx);

        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(findLeftMostBasket(fruits[i],0,n-1,sg_idx) == -1) ans ++;
        }
        return ans;
    }
};