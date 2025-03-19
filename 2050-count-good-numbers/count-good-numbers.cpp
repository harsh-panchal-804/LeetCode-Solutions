#pragma GCC target("avx2")
typedef long long ll;
class Solution {
public:
    ll binPow(ll a,ll b,const ll mod){
        ll ans=1;
        a%=mod;
        while(b){
            if(b&1){
                ans=(1ll*ans*a)%mod;
            }
            b>>=1;
            a=(1ll*a*a)%mod;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        const ll mod=1e9+7;
        if(!(n&1)){
            ll half=n/2;
            return (1ll *binPow(5,half,mod) * binPow(4,half,mod))%mod;
        }
        else{
            ll half=n/2;
            ll half2=n-n/2;
            return (1ll *binPow(4,half,mod) * binPow(5,half2,mod))%mod;
        }
    }
};