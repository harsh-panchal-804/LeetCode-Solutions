class Solution {
public:
    int dp[11][21][8][8][21][2][2];
    int solve(int n,string &num,int k,int even_count,int odd_count,int curr_rem,bool tight,bool lead){
        if(n==0){
            if(even_count==odd_count && curr_rem==0)return 1;
            return 0;
        }
        if(odd_count>5|| even_count>5)return 0;
        if(dp[n][k][even_count][odd_count][curr_rem][tight][lead]!=-1)return dp[n][k][even_count][odd_count][curr_rem][tight][lead];
        int ans=0;
        int ul=tight? num[num.size()-n]-'0' :9;
        for(int dig=0;dig<=ul;dig++){
           bool new_lead=(lead)&&(dig==0);
           int new_even=(even_count+ (dig%2==0 && !new_lead));
           int new_odd=(odd_count+ (dig%2==1 && !new_lead));
           ans+=solve(n-1,num,k,new_even,new_odd,(10*curr_rem+dig)%k,tight&(dig==ul),new_lead);
        }
        return dp[n][k][even_count][odd_count][curr_rem][tight][lead]=ans;

    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        memset(dp,-1,sizeof(dp));
        string a=to_string(low-1);
        int p=solve(a.size(),a,k,0,0,0,true,true);
        memset(dp,-1,sizeof(dp));
        string b=to_string(high);
       
        int q=solve(b.size(),b,k,0,0,0,true,true);
        return q-p;
        
    }
};