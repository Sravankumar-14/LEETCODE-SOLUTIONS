class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int a = 0;
        int b = 0;
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<vector<int>>result;
        while(a < size1 && b < size2)
        {
            if(nums1[a][0] == nums2[b][0])
            {
                result.push_back(
                    {
                        nums1[a][0],nums1[a][1] + nums2[b][1]
                    }
                );
                a++;
                b++;
            }
            else if(nums1[a][0] > nums2[b][0])
            {
                result.push_back(
                    {
                        nums2[b][0] , nums2[b][1]
                    }
                );
                b++;
            }
            else 
            {
                result.push_back(
                    {
                        nums1[a][0] , nums1[a][1]
                    }
                );
                a++;
            }
        }
        while(a < size1) 
        {
            result.push_back(
                {
                    nums1[a][0] , nums1[a][1]
                }
            );
            a++;
        }
        while(b < size2)
        {
            result.push_back(
                {
                    nums2[b][0] , nums2[b][1]
                }
            );
            b++;
        }
        return result;
    }
};