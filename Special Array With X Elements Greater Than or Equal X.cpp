class Solution {
public:
    int specialArray(vector<int>& nums) {
        for(int x=0;x<=nums.size();x++){
            int count=0;
            for(auto i  : nums){
                if(i>=x)count++;
            }
            if(count==x){
                return x;
            }
        }
        return -1;
        
    }
};