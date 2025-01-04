class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> fans;
        for(int i=0;i<numRows;i++){
            vector<int> ans(i+1,1);
            for(int j=1;j<i;j++){
                ans[j]=fans[i-1][j-1]+fans[i-1][j];
            }
            fans.push_back(ans);
        }
        return fans;
        
    }
};