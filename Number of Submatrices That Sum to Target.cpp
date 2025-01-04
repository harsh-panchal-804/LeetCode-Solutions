class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> vec(m+1,vector<int>(n+1,0));
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                vec[i][j]=matrix[i-1][j-1] +vec[i-1][j] +vec[i][j-1]-vec[i-1][j-1];
            }
        }
        int ans=0;
        for(int r1=1;r1<m+1;r1++){
            for(int r2=r1;r2<m+1;r2++){
                unordered_map<int,int> map;
                map[0]=1;
                for(int c=1;c<n+1;c++){
                    int curr=vec[r2][c]-vec[r1-1][c];
                    ans+=map[curr-target];
                    map[curr]++;
                }
            }
        }
        return ans;
    }
};