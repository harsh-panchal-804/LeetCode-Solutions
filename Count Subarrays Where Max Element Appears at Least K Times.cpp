class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int count=0;
        int mx=*max_element(nums.begin(),nums.end());
        vector<int> ind(1,-1);/// we initialise the array for one edje case- the begiining of loop
        for(int i=0;i<nums.size();i++){
            if(nums[i]==mx) ind.push_back(i);
        }
        if(ind.size()<k) return 0;
        for(auto i : ind) cout<<i<<" ";
        int n=nums.size();
        for(int i=1;i<=ind.size()-k;i++){
            long long int l=ind[i]-ind[i-1]-1;
            long long int r=n-ind[i+k-1]-1;
            count+=(1+l+r+(l*r));
        }
        return count;
    }
};
