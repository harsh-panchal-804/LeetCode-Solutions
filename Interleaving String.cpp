class Solution {
public:
    int dp[101][101];
    bool solve(string & s1,string & s2,string &s3,int i,int j){
        if(i==s1.size() && j==s2.size())return true;
        if(dp[i][j]!=-1)return dp[i][j];
        bool op1=i<s1.size()&& s1[i]==s3[i+j]? solve(s1,s2,s3,i+1,j):false;
        bool op2=j<s2.size()&& s2[j]==s3[i+j]?solve(s1,s2,s3,i,j+1):false;
        return dp[i][j]= (op1 || op2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        memset(dp,-1,sizeof(dp));
        if(m+n!=s3.size())return false;
        if(!m && !n)return true;
        // if(abs(n-m)>1)return false;
        return solve(s1,s2,s3,0,0);
    }
};