class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
      
        int sum = 0;

       
        for (int num : nums) {
            sum = (sum + num) % p;
        }
        if(sum%p==0)return 0;
        int rem=sum%p;

        vector<int> prefix(nums.size());
        prefix[0]=nums[0]%p;
        unordered_map<int,int> map;
        for(int i=1;i<nums.size();i++){
            prefix[i]=(prefix[i-1]+nums[i])%p;
        }
        for(auto i : prefix)cout<<i<<" ";
        map[0]=-1;
        int ans=INT_MAX;
        for(int i=0;i<prefix.size();i++){
            int curr=prefix[i];
            int need=(curr-rem+p)%p;
            if(map.find(need)!=map.end()){
                ans=min(ans,i-map[need]);
            }
            map[curr]=i;
        }
        return ans>=nums.size()?-1:ans;
    }
};