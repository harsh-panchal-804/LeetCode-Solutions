class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ideal_sum=n*(n+1)/2;
        int sum=0;
        for(auto i: nums){
            sum+=i;
        }
        cout<<ideal_sum<<sum;
        return ideal_sum-sum;
        
    }
};


//0 1 2 3 6
//n=3