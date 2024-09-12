class Solution {
public:
    int calHeight(int red, int blue)
    {
        int level = 0;
        int a = 1;
        bool turn = true;
        while(1)
        {
            level ++;
            if(turn)
            {
                if(red >= a) red -= a;
                else break;
            }
            else
            {
                if(blue >= a) blue -= a;
                else break;
            }
            a++;
            turn = !turn;
        }
        return level;
    }
    int maxHeightOfTriangle(int red, int blue) {
        int count1 = calHeight(red,blue);
        int count2 = calHeight(blue,red);

        // cout<<count1;
        return max(count1-1,count2-1);
    }
};