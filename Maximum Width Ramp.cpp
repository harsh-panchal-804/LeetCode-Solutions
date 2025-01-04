class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int> > vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        int ans=0;
        int minn=vec[0].second;
        for(int i=1;i<nums.size();i++){
            ans=max(ans,vec[i].second-minn);
            minn=min(minn,vec[i].second);
        }
        return ans;

    }
};