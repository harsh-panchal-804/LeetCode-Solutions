class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int startrow=0;
        int startcol=0;
        int endrow=matrix.size()-1;
        int endcol=matrix[0].size()-1;
        int count=0;
        vector<int>ans;
        
        while(count < m*n){
            //start row
            for(int i=startcol;i<=endcol && count<m*n;i++){
                ans.push_back(matrix[startrow][i]);
                count++;
            }
            startrow++;
            //end col
            for(int i=startrow;i<=endrow && count<m*n;i++){
                ans.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;
            //bottom row;
            for(int i=endcol;i>=startcol && count<m*n;i--){
                ans.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;
            // first col
            for(int i=endrow;i>=startrow && count<m*n;i--){
                ans.push_back(matrix[i][startcol]);
                count++;
            }
            startcol++;
            
        }
        cout<<count<<endl;

        return ans;
    }
};