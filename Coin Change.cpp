class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> ans(amount+1,INT_MAX);
        ans[0]=0;
        for(int i=1;i<amount+1;i++){
            for(auto j:coins){
                if(j<=i){
                    ans[i]=min(ans[i],ans[i-j]+1);
                }
            }
        }
        if(ans[ans.size()-1]==INT_MAX) return -1;
        return ans[ans.size()-1];

    }
};