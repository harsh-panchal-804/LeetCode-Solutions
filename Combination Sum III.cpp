class Solution {
public:
    void dfs(vector<vector<int>> &fans,vector<int> &ans,vector<int>&nums,int k,int n,int total,int i){
        if(ans.size()==k && total==n){
            fans.push_back(ans);
            return;
        }
        if(i>=nums.size()){
            return;
        }
        //include
        ans.push_back(nums[i]);
        dfs(fans,ans,nums,k,n,total+nums[i],i+1);
        //exclude
        ans.pop_back();
        dfs(fans,ans,nums,k,n,total,i+1);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        vector<int> ans;
        vector<vector<int>> fans;
        dfs(fans,ans,nums,k,n,0,0);
        return fans;

        
    }
};