class Solution {
public:
    void dfs(vector<int>&candidates,vector<vector<int>>&fans,vector<int>&ans,int target,int total,int i){
        if(total==target){
            fans.push_back(ans);
            return;
        }
         if(i>=candidates.size()||total>target){
            return;
        }
       
        //include i
        ans.push_back(candidates[i]);
        dfs(candidates,fans,ans,target,total+candidates[i],i+1);
        //exclude i
        ans.pop_back();
        while(i+1<candidates.size() && candidates[i]==candidates[i+1]){
            i=i+1;   
        }
        dfs(candidates,fans,ans,target,total,i+1);

       

        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> fans;
        vector<int>ans;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,fans,ans,target,0,0); 
        sort(fans.begin(),fans.end());
        fans.erase(unique(fans.begin(),fans.end()),fans.end());
        
        
        return fans;
        
    }
};