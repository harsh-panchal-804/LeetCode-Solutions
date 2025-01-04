class Solution {
public:
    bool dfs(vector<int>&matchsticks,vector<bool>& used,int i,int sum,int target, int k){
        if(k==0){
            return true;
        }
        if(sum==target){
            return dfs(matchsticks,used,0,0,target,k-1);
        }
        for(int j=i;j<matchsticks.size();j++){
            if(used[j] || sum+matchsticks[j]>target) continue;
            used[j]=true;
            if(dfs(matchsticks,used,j+1,sum+matchsticks[j],target,k)) return true;
            used[j]=false;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0) return false;
        int target=sum/4;
        vector<bool> used(matchsticks.size(),false);
        int k=4;
        return dfs(matchsticks,used,0,0,target,k);

        
    }
};