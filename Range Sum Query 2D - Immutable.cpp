class NumMatrix {
public:
    vector<vector<int>> vec;
    int m,n;
    NumMatrix(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vec.resize(m+1,vector<int>(n+1,0));
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                vec[i][j]=vec[i-1][j]+vec[i][j-1]-vec[i-1][j-1]+matrix[i-1][j-1];
            }
        } 
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        ans=vec[row2+1][col2+1]-vec[row2+1][col1]-vec[row1][col2+1]+vec[row1][col1];
        return ans;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */