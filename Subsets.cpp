class Solution {
public:
    void dfs(vector<int>&nums,vector<int> ans,vector<vector<int>> &fans,int i){
        if(i>=nums.size()){
            fans.push_back(ans);
            return;
        }
       
        //include i
        ans.push_back(nums[i]);
        dfs(nums,ans,fans,i+1);
        // exclude i
        ans.pop_back();
        dfs(nums,ans,fans,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> fans;
        vector<int> ans;
        dfs(nums,ans,fans,0);
        return fans;
        
    }
};