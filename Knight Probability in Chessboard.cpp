class Solution {
public:
    vector<vector<vector<double>>> dp;
    int hori[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int vert[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    double solve(int n,int k,int row,int column){
        if(row < 0 || column < 0 || row >= n || column >= n)
            return 0.0;
        if(k == 0)
            return 1.0;
        if(dp[k][row][column]!=-1.0)return dp[k][row][column];
        double ans=0.0;
        for(int i=0;i<8;i++){
            double temp=solve(n,k-1,row+hori[i],column+vert[i]);
            ans+=temp;
        }
        return dp[k][row][column]=(ans/8.0);
      
    }
    double knightProbability(int n, int k, int row, int column) {
       
        dp.resize(k + 1, vector<vector<double>>(n+1, vector<double>(n+1, -1.0)));
        return solve(n,k,row,column);
       
    }
};