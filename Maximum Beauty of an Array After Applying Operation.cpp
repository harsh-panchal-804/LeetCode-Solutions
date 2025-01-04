class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int,int> map;
        for(int i=0;i<nums.size();i++){
            int u=nums[i]-k;
            int v=nums[i]+k;
            map[u]++;
            map[v+1]--;
        }
        int ans=-1;
        int sum=0;
        for(auto i : map){
            sum+=i.second;
            ans=max(ans,sum);
        }
        return ans;
    }
};