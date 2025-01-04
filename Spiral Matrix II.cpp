class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        vector<int> col(n);
        for(int i=0;i<n;i++){
            matrix.push_back(col);
        }
        int num=1;
        int startrow=0;
        int startcol=0;
        int endrow=n-1;
        int endcol=n-1;
        while(num<=n*n){
            for(int i=startcol;i<=endcol && num<=pow(n,2);i++){
                matrix[startrow][i]=num++;
            }
            startrow++;
            for(int i=startrow;i<=endrow && num<=pow(n,2);i++){
                matrix[i][endcol]=num++;
            }
            endcol--;
            for(int i=endcol;i>=startcol && num<=pow(n,2);i--){
                matrix[endrow][i]=num++;
            }
            endrow--;
            for(int i=endrow;i>=startrow && num<=pow(n,2);i--){
                matrix[i][startcol]=num++;
            }
            startcol++;
        }
        return matrix;

        


        
    }
};