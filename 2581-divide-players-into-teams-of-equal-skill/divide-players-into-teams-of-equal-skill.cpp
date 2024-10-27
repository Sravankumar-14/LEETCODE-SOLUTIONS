class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int a = 0;
        int b = skill.size()-1;
        int temp = skill[a] + skill[b];
        long long ans = 0;
        while(a < b)
        {
            int t = skill[a] + skill[b];
            if(t != temp) return -1;
            int k = skill[a] * skill[b];
            ans += k;
            a++;
            b--;
        }
        return ans;
    }
};