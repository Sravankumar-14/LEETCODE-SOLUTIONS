class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int currentGas = 0;
        int index = 0;
        for(int i=0; i<gas.size(); i++)
        {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];
            if(currentGas < 0)
            {
                index = i+1;
                currentGas = 0;
            }
        }
        return (totalGas < totalCost) ? -1 : index;
    }
};