class Solution {
public:
    int helper(vector<int> bloom,int mid,int k){
        int boq=0;
        int count=0;
        for(int i=0;i<bloom.size();i++){
            if(bloom[i]<=mid){
                count++;
            }
            else count=0;
            if(count==k){
                boq++;
                count=0;
            }
        }
        return boq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1;
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;;
        while(l<=r){
            int mid=(l+r)/2;
            if(helper(bloomDay,mid,k)>=m){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
        
    }
};