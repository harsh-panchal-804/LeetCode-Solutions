class Solution {
public:
    int dp[605][105][105];
    int solve(vector<string>& strs, int curr_m,int curr_n,int i,int m,int n){
        if(i>=strs.size())return 0;
        if(dp[i][curr_m][curr_n]!=-1)return dp[i][curr_m][curr_n];
        string temp=strs[i];
        int z_count=count(temp.begin(),temp.end(),'0');
        int o_count=count(temp.begin(),temp.end(),'1');
        /// not take
        int op1=solve(strs,curr_m,curr_n,i+1,m,n);
        /// take
        int op2=0;
        if(curr_m+z_count<=m && curr_n+o_count<=n){
            op2=1+solve(strs,curr_m+z_count,curr_n+o_count,i+1,m,n);
        }
        return dp[i][curr_m][curr_n]=max(op1,op2);


    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,0,0,0,m,n);


    }
};