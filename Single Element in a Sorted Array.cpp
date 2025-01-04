class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int m=left+(right-left)/2;
            if(( m-1 <0 || nums[m-1]!=nums[m]) && (m+1==nums.size() ||nums[m]!=nums[m+1])){
                return nums[m];
            }
            else{
                int lsize;

                if(nums[m-1]==nums[m]){
                   lsize=m-1;
                }
                else if(nums[m-1]!=nums[m]){
                    lsize=m;
                }
                if(lsize%2!=0) right=m-1;
                else left=m+1;

            }
        }
        return 0;
        
    }
};