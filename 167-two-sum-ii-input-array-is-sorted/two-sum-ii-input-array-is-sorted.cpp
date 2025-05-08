class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        map<int,int>mp;
        for(int i=0; i<numbers.size(); i++)
        {
            int first = target - numbers[i];
            if(mp.find(first) != mp.end())
            {
                return{mp[first] , i+1};
            }
            else
            {
                mp[numbers[i]] = i+1;
            }
        }
        return {};
    }
};