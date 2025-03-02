class Solution {
public:
    int findFib(vector<int>& arr, int a, int b, set<int>& st)
    {
        int len = 2;
        int sum = a+b;
        while(st.find(sum) != st.end())
        {
            len ++;
            a = b;
            b = sum;
            sum = a+b;
        }
        return len>2?len:0;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int maxLength = 0;
        set<int>st;
        for(int i : arr) st.insert(i);
        for(int i=0; i<arr.size(); i++)
        {
            for(int j=i+1; j<arr.size(); j++)
            {
                int length = findFib(arr,arr[i],arr[j],st);
                maxLength = max(maxLength , length);
            }
        }
        return maxLength;
    }
};