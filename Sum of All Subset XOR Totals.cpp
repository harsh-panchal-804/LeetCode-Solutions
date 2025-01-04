class Solution {
public:
    
    int total;
    void dfs(int i,vector<int>& nums,vector<int>&ans){
        if(i>=nums.size()){
            int sum=0;
            for(auto j : ans){
                cout<<j;
                sum=sum^j;
            }
            total+=sum;
            cout<<""<<endl;
            return;
        }
        ans.push_back(nums[i]);
        dfs(i+1,nums,ans);
        ans.pop_back();
        dfs(i+1,nums,ans);
        return;
        

    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> ans;
        dfs(0,nums,ans);
        return total;
        
    }
};