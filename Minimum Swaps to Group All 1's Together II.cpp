class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int total=count(nums.begin(),nums.end(),1);
        vector<int> copy=nums;
        for(auto i : copy)nums.push_back(i);
        int ones=0;
        int zeroes=0;
        for(int i=0;i<total;i++){
            if(nums[i]==1)ones++;
            else zeroes++;
        }
        cout<<zeroes;
        int ans=INT_MAX;

        for(int i=1;i<nums.size()-total+1;i++){
            if(nums[i-1]==0){
                zeroes--;
            }
            if(nums[total+i-1]==0)zeroes++;
            ans=min(ans,zeroes);
        }
        return ans;

        
    }
};