class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> ps(n,0),ss(n,0);
        ps[0]=height[0];
        ss[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            ps[i]=max(ps[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            ss[i]=max(ss[i+1],height[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            if(ps[i]>height[i] && ss[i]>height[i])
            {
                sum+=min(ps[i],ss[i])-height[i];
            }

        }
        return sum;
    }
};