class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        /// 3 sum for loop then 2 pointer
        sort(nums.begin(),nums.end());
        int count=0;
        for(int r=nums.size()-1;r>=2;r--){
            int mid=r-1;
            int l=0;
            while(l<mid){
                if(nums[l]+nums[mid]>nums[r]){
                    count+=(mid-l);
                    mid--;
                }
                else l++;
                
            }

        }


        
        return count;
        
    }
};