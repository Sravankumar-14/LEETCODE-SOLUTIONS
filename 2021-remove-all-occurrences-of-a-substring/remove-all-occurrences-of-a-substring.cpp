class Solution {
public:
    string removeOccurrences(string s, string part) {
        int partSize = part.size();
        bool iterate = true;
        while(s.size() >= partSize && iterate)
        {
            iterate = false;
            for(int i=0; i<=s.size()-partSize; i++)
            {
                string str = s.substr(i,partSize);
                if(str == part)
                {
                    s = s.substr(0,i) + s.substr(i+partSize);
                    iterate = true;
                    break;
                }
            }
        }
        return s;
    }
};