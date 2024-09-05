class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int a = target[0];
        int b = target[1];
        int ourDist = abs(a) + abs(b);
        cout<<ourDist<<"\n";
        for(auto& row : ghosts)
        {
            int p = row[0];
            int q = row[1];
            int ghostDist = abs(p-a) + abs(q-b);
            cout<<ghostDist<<" ";
            if(ghostDist <= ourDist) return false;
        }
        return true;
    }
};