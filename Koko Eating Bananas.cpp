class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int l=1;
        long long int r=*max_element(piles.begin(),piles.end());
        
        long long int ans=r;
        while(l<=r){
            long long int mid=(l+r)/2;
            long long int count=0;
            for(auto i:piles){
                count+=(i+mid-1)/mid;
            }
            if(count<=h){
                ans=min(ans,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            
        }
        return ans;
    }
};
