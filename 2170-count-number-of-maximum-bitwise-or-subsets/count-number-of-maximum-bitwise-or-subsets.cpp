class Solution {
public:
    void rec(vector<int>& nums, int maxi, int n, int index, int& count, int sum)
    {
        if (sum == maxi) count++;
        for (int i = index; i < n; i++) {
            rec(nums, maxi, n, i + 1, count, sum | nums[i]);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        for (int i : nums) maxi = maxi | i;
        int count = 0;
        rec(nums, maxi, n, 0, count, 0);
        return count;
    }
};
