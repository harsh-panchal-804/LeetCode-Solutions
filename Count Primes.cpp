class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n,1);
        if(n==1 || n==0) return 0; 
        primes[0]=primes[1]=0;
        for(int i=2;i<n;i++){
            if(primes[i]==1){
                for(int j=2*i;j<n;j+=i){
                    primes[j]=0;
                }
            }
        }
        int count=0;
        for(auto i : primes){
            if(i==1)++count;
        }
        return count;
        
    }
};