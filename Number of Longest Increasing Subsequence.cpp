class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        count[i]=0;
                    }
                    if(dp[j]+1==dp[i]){
                        count[i]+=count[j];
                    }
                }
            }
        }
        int max=*max_element(dp.begin(),dp.end());
        cout<<max;
        int ans=0;
        for(int i=0;i<dp.size();i++){
            if(dp[i]==max){
                ans+=count[i];
            }
        }
        return ans;
    }
};