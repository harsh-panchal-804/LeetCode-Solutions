class Solution {
public: 
    int dp[101][10][2][2];
    int mod=1e9+7;
    int solve(int n,string & num,int prev,bool tight,bool valid){
        if(n==0){
            if(valid)return 1;
            return 0;
        }
        if(dp[n][prev][tight][valid]!=-1)return dp[n][prev][tight][valid];
        int ul=tight? num[num.size()-n]-'0':9;
        int ans=0;
        for(int dig=0;dig<=ul;dig++){
            if(!valid && (dig==0)){
                ans=(ans+solve(n-1,num,prev,tight&(dig==ul),false))%mod;
            }
            else if(!valid && dig!=0){
                ans=(ans+solve(n-1,num,dig,tight&(dig==ul),true))%mod;
            }
            else if(abs(dig-prev)==1){
                ans=(ans+solve(n-1,num,dig,tight&(dig==ul),true))%mod;
            }
        }
        return  dp[n][prev][tight][valid]= ans;
    }
    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof(dp));
        int a=solve(low.size(),low,0,true,false);
        memset(dp,-1,sizeof(dp));
        int b=solve(high.size(),high,0,true,false);
        bool flag=false;
        for(int i=1;i<low.size();i++){
            if(abs(low[i]-low[i-1])!=1)flag=true;
        }
        if(flag==false)a--;
        return (b-a+mod)%mod;
        
    }
};