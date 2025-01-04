class Solution {
public:
    bool dfs(vector<int>&nums,vector<bool>&used, int k,int i,int sum,int target){
        if(k==0){
            return true;
        }
        if(sum>target) return false;
        if(sum==target){
            return dfs(nums,used,k-1,0,0,target);
        }
        for(int j=i;j<nums.size();j++){
            if(used[j] || sum+nums[j]>target) continue;
            used[j]=true;
            if(dfs(nums,used,k,j+1,sum+nums[j],target)) return true;
            used[j]=false;
            if(sum==0)break;
        }
        return false;
        
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int acc=accumulate(nums.begin(),nums.end(),0);
        vector<bool> used (nums.size(),false);
        sort(nums.begin(),nums.end(), greater<int>());
        if(acc%k!=0) return false;
        int target=acc/k;
        if(nums[0]>target) return false;
        return dfs(nums,used,k,0,0,target);
    }
};