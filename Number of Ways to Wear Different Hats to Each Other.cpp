class Solution {
public:
    int mod=1e9+7;
    int dp[41][(1<<10)+1];
    int solve(int hat,int mask, unordered_map<int,vector<int>> &hats_people,int n){
        if(mask==(1<<n)-1){
            return 1;
        }
        if(hat>40)return 0;
        if(dp[hat][mask]!=-1)return dp[hat][mask];
       
        int ans=solve(hat+1,mask,hats_people,n);
       
        for(auto people:hats_people[hat]){
            if(mask&(1<<people))continue;
            ans=(ans+solve(hat+1,mask|(1<<people),hats_people,n))%mod;
        }
        return dp[hat][mask]=ans;
        
    }
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();
        unordered_map<int,vector<int>> hats_people;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<hats.size();i++){
            for(auto hat: hats[i]){
                hats_people[hat].push_back(i);
            }
        }
        return solve(0,0,hats_people,n);

    }
};