class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int i=0;
        int ans=0;
        for(int j=0;j<nums.size();j++){
            map[nums[j]]++;
            while(map[nums[j]]>k){
                map[nums[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        
        return ans;
        
    }
};