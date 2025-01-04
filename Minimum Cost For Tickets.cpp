class Solution {
public:
    int dp[366];
    int solve(vector<int>&days,vector<int>&costs,int i){
        if(i>=days.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int op1=costs[0]+solve(days,costs,i+1);
        int j=i;
        int ul=days[i]+7;
        while(j<days.size()&& days[j]<ul)j++;
        int op2=costs[1]+solve(days,costs,j);
        j=i;
        ul=days[i]+30;
        while(j<days.size()&&days[j]<ul)j++;
        int op3=costs[2]+solve(days,costs,j);
        return dp[i]=min({op1,op2,op3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(days,costs,0);
    }
};