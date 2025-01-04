class Solution {
public:
    int binMul(int a,int b,const int mod){
        int ans=0;
        while(b){
            if(b&1){
                ans=(ans+a)%mod;
            }
            a=(a+a)%mod;
            b>>=1;
        }
        return ans;
    }
    int binExp(int a, int b,const int mod){
        a%=mod;
        int ans=1;
        while(b>0){
            if(b&1){
                ans=binMul(ans,a,mod);
            }
            a=binMul(a,a,mod);
            b>>=1;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        const int etf=1140;
        const int mod=1337;
        int q=0;
        int n=b.size();
        for(auto val:b){
            q=(val+10*q)% etf;
        }
        q+=etf;
        cout<<q<<"\n";
        return binExp(a,q,mod);
        
    }
};