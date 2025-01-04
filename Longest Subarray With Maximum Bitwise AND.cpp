class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mxx=*max_element(nums.begin(),nums.end());
        int len=0;
        int streak=0;
        for(auto & x:nums){
            if(x==mxx){
                streak++;
                len=max(len,streak);
            }
            else{
                streak=0;
            }
        }
        return len;
        
    }
};