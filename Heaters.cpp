class Solution {
public:
    int distance(vector<int>& heaters,int house){
        int l=0;
        int r=heaters.size()-1;
        int dist=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            dist=min(dist,abs(heaters[mid]-house));
            if(heaters[mid]<house){
                l=mid+1;
            }
            else r=mid-1;
        }
        return dist;

    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ans=INT_MIN;
        for(auto house:houses){
            ans=max(ans,distance(heaters,house));
        }
        return ans;
        
        
    }
};