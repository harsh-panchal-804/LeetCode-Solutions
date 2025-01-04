class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int r=1;r<matrix.size();r++){
            for(int c=0;c<matrix[0].size();c++){
                int mid,left,right;
                mid=matrix[r-1][c];
                left=c>0 ? matrix[r-1][c-1] : INT_MAX;
                right=c<matrix.size()-1 ? matrix[r-1][c+1] : INT_MAX;
                matrix[r][c]=matrix[r][c] + min({mid,left,right});
            }
        }
        return *min_element(matrix[matrix.size()-1].begin(),matrix[matrix.size()-1].end());
        
    }
};