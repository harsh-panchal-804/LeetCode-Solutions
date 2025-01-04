class Solution {
public: 
    int dp[11][2][11];
    int solve(int n,string &num,bool tight,int sum){
        if(n==0)return sum;
        if(dp[n][tight][sum]!=-1)return dp[n][tight][sum];
        int ans=0;
        int ul=tight?num[num.size()-n]-'0':9;
        for(int dig=0;dig<=ul;dig++){
            ans+=solve(n-1,num,tight&(dig==ul),sum+(1==dig));
        }
        return dp[n][tight][sum]=ans;
    }
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string num=to_string(n);
        return  solve(num.size(),num,true,0);
    }
};