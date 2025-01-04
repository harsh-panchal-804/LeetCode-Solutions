class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows=triangle.size();
        for(int r=rows-2;r>=0;--r){
            for(int c=0;c<triangle[r].size();c++){
                int down=triangle[r+1][c];
                int nxtdown=triangle[r+1][c+1];
                triangle[r][c]=triangle[r][c]+min(down,nxtdown);
            }
        }
        return triangle[0][0];
        
    }
};