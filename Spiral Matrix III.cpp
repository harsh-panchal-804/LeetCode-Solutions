class Solution {
public:
    vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int x=rStart;
        int y=cStart;
        vector<vector<int>>ans;
        int step=1;
        int mode=0;
        while(ans.size()<rows*cols){
            for(int t=0;t<2;t++){
                for(int i=0;i<step;i++){
                if(x>=0 && y>=0 &&x<rows && y< cols){
                    ans.push_back({x,y});
                }
                x+=dirs[mode%4].first;
                y+=dirs[mode%4].second;
                }
                mode++;
            }
            step++;
        }
        return ans;
        
    }
};