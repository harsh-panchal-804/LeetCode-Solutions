class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1);
        dp[0]=1;
        for(int i=1;i<target+1;i++){
            for(auto item: nums){
                if(i>=item){
                    dp[i]+=dp[i-item];
                }
            }
        }
        return dp[target];
        
    }
};