class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0;
        for(int i=0; i<3; i++)
        {
            for(int j=a; j<nums.size(); j++)
            {
                if(nums[j] == i)
                {
                    swap(nums[j] , nums[a]);
                    a++;
                    // for(int num : nums) cout<<num<<" ";
                    // cout<<endl;
                }
            }
        }
    }
};