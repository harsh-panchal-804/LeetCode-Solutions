class Solution {
public:
    void dfs(vector<vector<int>>&fans,vector<int>&ans,int i,vector<int>&nums){
        if(i>=nums.size()){
            fans.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        dfs(fans,ans,i+1,nums);
        ans.pop_back();
       
        while(i+1<nums.size()&&nums[i]==nums[i+1]){
            i++;
        }
        dfs(fans,ans,i+1,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> fans;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        dfs(fans,ans,0,nums);
        return fans;
        
    }
};