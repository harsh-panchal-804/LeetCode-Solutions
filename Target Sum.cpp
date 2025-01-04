class Solution {
public:
    int dfs(vector<int>&nums,int target,int total,int i){
        if(i==nums.size() && total==target){
            return 1;
        }
        
        else if(i>=nums.size()){
            return 0;
        }
        
        return dfs(nums,target,total+nums[i],i+1)+dfs(nums,target,total-nums[i],i+1);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       
        return dfs(nums,target,0,0);
        
        
    }
};