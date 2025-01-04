class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int> vec;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=2){
                bool prime=true;
                for(int j=2;j<=sqrt(nums[i]);j++){
                    if(nums[i]%j==0){
                        prime =false;
                        break;
                    }
                }
                if(prime)vec.push_back(i);
            
            }
           
           
        }
        for(auto i : vec)cout<<i;
        if(vec.empty())return 0;
        return vec.back()-vec.front();
        
    }
};