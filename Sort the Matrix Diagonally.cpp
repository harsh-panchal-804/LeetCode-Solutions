class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,priority_queue<int,vector<int>, greater<int>>> map;
        int r=mat.size();
        int c=mat[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                map[i-j].push(mat[i][j]);
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mat[i][j]=map[i-j].top();
                map[i-j].pop();
            }
        }
        return mat;

        
    }
};