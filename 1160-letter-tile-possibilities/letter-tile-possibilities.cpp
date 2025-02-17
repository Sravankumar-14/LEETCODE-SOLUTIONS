class Solution {
public:
    int countPossibilities(vector<int>& freq)
    {
        int ways = 0;
        for(int i=0; i<26; i++)
        {
            if(freq[i] > 0)
            {
                freq[i] --;
                ways += 1 + countPossibilities(freq);
                freq[i] ++;
            }
        }
        return ways;
    }
    int numTilePossibilities(string tiles) {
        vector<int>freq(26,0);
        for(char ch : tiles)
        {
            freq[ch - 'A'] ++;
        }
        return countPossibilities(freq);
    }
};