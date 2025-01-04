class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int cost=0;
        for(int r=homePos[0];r!=startPos[0];r+= (r>startPos[0]?-1:1)){
            cost+=rowCosts[r];
            ////cout<<rowCosts[r+1];
        }
        for(int r=homePos[1];r!=startPos[1];r+= (r>startPos[1]?-1:1)){
            cost+=colCosts[r];
        }
        return cost;

        
    }
};