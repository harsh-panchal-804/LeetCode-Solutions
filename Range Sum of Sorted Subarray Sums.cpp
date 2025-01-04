class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int mod=1e9+7;
        vector<long long> sums;
        for(int i=0;i<n;i++){
            long long temp=0;
            for(int j=i;j<n;j++){
                temp+=nums[j];
                sums.push_back(temp);
            }
        }
        sort(sums.begin(),sums.end());
        long long ans=0;
        for(int i=left-1;i<=right-1;i++){
            ans=(ans+sums[i])%mod;
        }
        // for(auto i :sums){
        //     cout<<i<<" ";
        // }
        return ans;

        
    }
};