class Solution {
public:
    int count=0;
    bool check(vector<int>& ans,int x,int k){
        for(auto i : ans){
            if(abs(i-x)==k){
                return false;
            }
        }
        return true;
    }
    void dfs(int i,int k,vector<int>&nums,vector<int>&ans){
        if(i>=nums.size()){
            count++;
            return;
        }
        if(check(ans,nums[i],k)){
        ans.push_back(nums[i]);
        dfs(i+1,k,nums,ans);
        ans.pop_back();
        }
        dfs(i+1,k,nums,ans);
        ///return;
        
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> ans;
   
        ///sort(nums.begin(),nums.end());
        dfs(0,k,nums,ans);
        // return fans.size();
        return count-1;
        
    }
};