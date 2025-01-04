class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        vector<int> ans(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            if(abs(nums[end])>abs(nums[start])){
                ans[i]=nums[end]*nums[end];
                end--;
            }
            else{
                ans[i]=nums[start]*nums[start];
                start++;
            }
        }
        return ans;

        
    }
};