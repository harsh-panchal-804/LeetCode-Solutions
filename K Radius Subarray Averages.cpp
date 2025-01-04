class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long > prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        // for(auto i : prefix){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i+k>=n || i-k<0)ans.push_back(-1);
            else{
                long long a=i-k-1>=0? prefix[i-k-1]:0;
                long long b=prefix[i+k]-prefix[i];
                // cout<<a<<" "<<b<<"\n";
                ans.push_back((prefix[i]-a+b)/(2*k+1));
            }
        }
        return ans;
        
    }
};