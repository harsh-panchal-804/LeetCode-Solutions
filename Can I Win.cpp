class Solution {
public:
    bool solve(int mask,int curr_sum,int max_num, int desired ,unordered_map<int,bool> &dp){
        if(curr_sum>=desired){
            return false;
        }
        if(dp.count(mask))return dp[mask];
        for(int dig=1;dig<=max_num;dig++){
            if((mask&(1<<dig))==0){
                bool op=solve(mask|(1<<dig),curr_sum+dig,max_num,desired,dp);
                if(!op){
                    dp[mask]=true;
                    return true;
                }
            }
        }
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        /// dp[i][mask][running_total]
        ///if()
        int sumPossible = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (sumPossible < desiredTotal) return false;
        unordered_map<int,bool> dp;
        if(desiredTotal<=0)return true;
        return solve(0,0,maxChoosableInteger,desiredTotal,dp);
    }
};