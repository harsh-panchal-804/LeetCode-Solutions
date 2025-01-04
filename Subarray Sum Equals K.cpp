class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int tsum=0;
        for(int i=0;i<nums.size();i++){
            tsum=nums[i];
            if(tsum==k) count++; 
            for(int j=i+1;j<nums.size();j++){
                tsum+=nums[j];
                if(tsum==k) count++;
            }
        }
        return count;
        
    }
};