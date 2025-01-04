class Solution {
public:
    int mod=1e9+7;
    int dp[5005][10][10];
    int solve(int n,int row,int col){
        if(row<0||col<0|| row>3|| col>2)return 0;
        if((row==3&& col==0)||(row==3&&col==2))return 0;
        if(n==0){
            return 1;
        }
        if(dp[n][row][col]!=-1)return dp[n][row][col];
        int ans=0;
        for(auto y:{-2,2}){
            for(auto x:{-1,1}){
                ans=(ans+solve(n-1,row+y,col+x))%mod;
            }
        }
        for(auto y:{-2,2}){
            for(auto x:{-1,1}){
                ans=(ans+solve(n-1,row+x,col+y))%mod;
            }
        }
        return dp[n][row][col]=ans;

    }
    int knightDialer(int n) {
        int count=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                count=(count+solve(n-1,i,j))%mod;
            }
        }
        count=(count+solve(n-1,3,1))%mod;
        return count;
    }
};