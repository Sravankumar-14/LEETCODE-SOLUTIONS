class Solution {
public:
    int lastRemaining(int n) {
        int step = 1;
        int head = 1;
        int rem = n;
        bool left = true;
        while(rem > 1)
        {
            if(left || rem % 2 == 1) head += step;
            step *= 2;
            rem /= 2;
            left = !left;
        }
        return head;
    }
};