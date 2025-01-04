class Solution {
public:
    int arrangeCoins(int n) {
        long long int l=1;
        long long int r=n;
        long long int ans=INT_MIN;
        while(l<=r){
            long long int mid=(l+r)/2;
            long long int coins=mid*(mid+1)/2;
            
            if(coins>n) r=mid-1;
            else{
                l=mid+1;
                ans=max(ans,mid);
            }
        }
        return ans;
        
    }
};