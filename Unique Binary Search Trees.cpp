class Solution {
public:
    long NCR(int n,int r){
        long ans=1;
        for(int i=0;i<r;i++){
            ans*=(n-i);
            ans/=(i+1);
        }
        return ans;
    }
    int numTrees(int n) {
        return NCR(2*n,n)/(n+1);
        
    }
};