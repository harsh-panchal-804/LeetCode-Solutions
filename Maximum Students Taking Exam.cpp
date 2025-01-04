class Solution {
public:
    int dp[9][(1<<9)+1];
    int solve(int curr,int prev_mask,vector<vector<char>>& seats,int rows,int cols){
        if(curr>=rows)return 0;
        int ans=0;
        if(dp[curr][prev_mask]!=-1)return dp[curr][prev_mask];
        for(int mask=0;mask < (1<<cols);mask++){
            if(mask & (mask>>1))continue;
            int running_total=0;
            bool valid=true;
            for(int j=0;j<cols;j++){
                if(mask&(1<<j)){
                    if(seats[curr][j]=='#'){
                        valid=false;
                        break;
                }
                running_total++;
                if(j>0 && prev_mask &(1<<(j-1)))valid=false;
                if(j<cols && prev_mask & (1<<(j+1)))valid=false;
                }
            }
            if(valid){
                int temp=running_total+solve(curr+1,mask,seats,rows,cols);
                ans=max(ans,temp);
            }
        }
        return dp[curr][prev_mask]=ans;
    }
    int maxStudents(vector<vector<char>>& seats) {
        int rows=seats.size();
        int cols=seats[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,seats,rows,cols);

    }
};