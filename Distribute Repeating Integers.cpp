class Solution {
public:
    int dp[51][(1<<11)+1];
    bool valid(int mask,int freq,vector<int>&quantity,int prev){
        if(prev&mask)return false;/// prev==mask gives tle
        int sum=0;
        for(int i=31;i>=0;i--){
            if(mask&(1<<i)){
                sum+=quantity[i];
            }
        }
        return freq>=sum;
    }
    bool solve(int pos,int mask,vector<int>&quantity,vector<int>&freq){
        int n=freq.size();
        int m=quantity.size();
        if(mask==(1<<m)-1)return true;
        if(pos>=n)return false;
        if(dp[pos][mask]!=-1)return dp[pos][mask];
        int ans=false;
        for(int i=0;i<(1<<m);i++){
            if(valid(i,freq[pos],quantity,mask)){
                ans=ans|solve(pos+1,mask|i,quantity,freq);
                if(ans)return dp[pos][mask]=ans;
            }
        }
        return dp[pos][mask]=false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        vector<int> freq;
        unordered_map<int,int> map;
        for(auto i : nums){
            map[i]++;
        }
        memset(dp,-1,sizeof(dp));
        for(auto i:map){
            freq.push_back(i.second);
        }
        return solve(0,0,quantity,freq);

    }
};