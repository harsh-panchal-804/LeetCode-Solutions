class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> map;
        map[0]=-1;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]==0? -1:1;
            if(map.find(sum)!=map.end()){
                ans=max(ans,i-map[sum]);
            }
            else{
                map[sum]=i;
            }
        }
        return ans;
        
    }
};