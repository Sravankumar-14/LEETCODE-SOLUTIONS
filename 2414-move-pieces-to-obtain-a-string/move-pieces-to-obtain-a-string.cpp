class Solution {
public:
    bool canChange(string start, string target) {
        int startSize = start.size();
        int a = 0;
        int b = 0;
        while(a < startSize && b < startSize)
        {
            while(a < startSize-1 && start[a] == '_') a++;
            while(b < startSize-1 && target[b] == '_') b++;
            if(start[a] == target[b])
            {
                if(start[a] == 'L') 
                {
                    if(a < b) return false;
                }
                else if(a > b) return false;
            } 
            else return false;
            a++;
            b++;
        }
        while(a < startSize) if(start[a++] != '_') return false;
        while(b < startSize) if(target[b++] != '_') return false;
        return true;
    }
};