class Solution {
public:
    long long fib(int n){
        double phi=(1+sqrt(5))/2;
        return round((pow(phi,n))/sqrt(5));
    }
    int findMinFibonacciNumbers(int k) {
        vector<long long> vec;
        int j=1;
        while(true){
            if(fib(j)<=k){
                vec.push_back(fib(j));
                j++;
            }
            else break;
        }
        
        for(auto i : vec)cout<<i<<" ";
        int ans=0;
        for(int i=vec.size()-1;i>=0;i--){
            while(k>=vec[i] && vec[i]!=0){
                k-=vec[i];
                ans++;
            }
        }
        return ans;
        
    }
};