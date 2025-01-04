class Solution {
public:
    int dp[35][350][2];
    int mod=1e9+7;
    int solve(int n,string num,int min_sum,int max_sum,int curr_sum,bool tight){
        if(n==0){
            if(curr_sum>=min_sum && curr_sum<=max_sum){
                return 1;
            }
            return 0;
        }
        if(dp[n][curr_sum][tight]!=-1)return dp[n][curr_sum][tight];
        int ans=0;
        int ul=tight? num[num.size()-n]-'0' :9;
        for(int dig=0;dig<=ul;dig++){
            ans=(ans+solve(n-1,num,min_sum,max_sum,curr_sum+dig,tight&(dig==ul)))%mod;
        }
        return dp[n][curr_sum][tight]=ans%mod;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        int b=solve(num2.size(),num2,min_sum,max_sum,0,true);
        memset(dp,-1,sizeof(dp));
        int a=solve(num1.size(),num1,min_sum,max_sum,0,true);
        int extra=0;
        for(auto i : num1){
            extra+=i-'0';
        }
        if(extra>=min_sum&& extra<=max_sum)a--;
        return (b-a+mod)%mod;
    }
};