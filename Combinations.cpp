class Solution {
public:
    void dfs(vector<vector<int>> &fans,vector<int> &ans,int n,int k,int start){
        if(ans.size()==k){
            fans.push_back(ans);
            return;
        }
        for(int i=start;i<=n;i++){
            ans.push_back(i);
            dfs(fans,ans,n,k,i+1);
            ans.pop_back();
          
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> fans;
        vector<int> ans;
        dfs(fans,ans,n,k,1);
        return fans;
        
    }
};