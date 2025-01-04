class Solution {
public:
    void dfs(vector<vector<int>>& fans,vector<int>& nums,vector<int> &ans,int i){
        int n=nums.size();
        if(i>=n){
            if(ans.size()>1)
            fans.push_back(ans);
            return;
        }
        if(ans.empty() || nums[i]>=ans.back()){
            ans.push_back(nums[i]);
            dfs(fans,nums,ans,i+1);
            ans.pop_back();  
        }
        ///if(!ans.size() || nums[i]<ans.back())
        dfs(fans,nums,ans,i+1);
        
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> fans;
        vector<int> ans;
        dfs(fans,nums,ans,0);
        sort(fans.begin(),fans.end());
        fans.erase(unique(fans.begin(),fans.end()),fans.end());
        return fans;
        
    }
};