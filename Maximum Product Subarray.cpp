class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1;
       
        int maxans=INT_MIN;
        for(int r=0;r<nums.size();r++){
            prod*=nums[r];
            maxans=max(maxans,prod);
            if(prod==0) prod=1;

        }


        prod=1;
        int max2=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            prod*=nums[i];
            max2=max(max2,prod);
            if(prod==0) prod=1;
        }
        return max(maxans,max2);
        
    }
};