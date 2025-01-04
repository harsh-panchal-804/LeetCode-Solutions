class Solution {
public:
    int mod=1e9+7;
    int dp[(int)1e5][27];
    int solve(int n,char curr_char){
        if(n==0)return 1;
        if(dp[n][curr_char-'a']!=-1)return dp[n][curr_char-'a'];
        int ans=0;
        if(curr_char=='a'){
            ans=(ans+solve(n-1,'e'))%mod;
        }
        else if(curr_char=='e'){
            ans=(ans+solve(n-1,'a'))%mod;
            ans=(ans+solve(n-1,'i'))%mod;
        }
        else if(curr_char=='i'){
            ans=(ans+solve(n-1,'a'))%mod;
            ans=(ans+solve(n-1,'e'))%mod;
            ans=(ans+solve(n-1,'o'))%mod;
            ans=(ans+solve(n-1,'u'))%mod;
        }
        else if(curr_char=='o'){
            ans=(ans+solve(n-1,'i'))%mod;
            ans=(ans+solve(n-1,'u'))%mod;
        }
        else{
            ans=(ans+solve(n-1,'a'))%mod;
        }
        return dp[n][curr_char-'a']=ans;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(auto i :{'a','e','i','o','u'}){
            ans=(ans+solve(n-1,i))%mod;
        }
        return ans;

    }
};