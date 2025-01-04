class Solution {
public:
    int rob(vector<int>& nums) {
        /// if(n<0) return 0
        /// if(n==0)return nums[0];
        // int inc=solve(n-2)+nums[n];
        // int exc=solve(n-1);
        // ans=max(inc,exc);
        // rteunr ans;



        ///if(i>size)return 0
        ////if(i==size-1)return nums[i]
        // int inc=solve(i+2)+nums[i];
        // int exc=solve(i+1);
        // return max(inc,exc);
        /// 2 1 1 2 
        /// 
        int n=nums.size();
        if(n==0)return 0;
        vector<int> dp(nums.size()+1);
    
        dp[nums.size()]=0;
        dp[nums.size()-1]=nums[nums.size()-1];
        for(int i=n-2;i>=0;i-- ){
            dp[i]=max(dp[i+1],dp[i+2]+nums[i]);
        }
        return dp[0];


        
    }
};