class Solution {
public:
    int dp[11][2][2];
    int solve(int n,string &num,bool tight,vector<string>&digits,bool valid){
        if(n==0){
            if(valid)return 1;
            return 0;
        }
        if(dp[n][tight][valid]!=-1)return dp[n][tight][valid];
        int ul=tight? num[num.size()-n]-'0':9;
        int ans=0;
        if(!valid){
            ans+=solve(n-1,num,false,digits,false);
        }
        for(auto d:digits){
            int dig=stoi(d);
            if(dig>ul)continue;
            ans+=solve(n-1,num,tight&(dig==ul),digits,true);
        }
        return dp[n][tight][valid]=ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(dp,-1,sizeof(dp));
        string num=to_string(n);
        return solve(num.size(),num,true,digits,false);

    }
};