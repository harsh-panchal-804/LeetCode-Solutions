class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
         
         sort(nums.begin(),nums.end());
         int start = 0;
         int end   = nums[nums.size()-1] - nums[0];
         int ans = end;
         while(start <= end){
            int mid = (start + end)/2;
            if(fun(nums,mid) >= k) //we have k or more than k pairs having diff <= mid
            {
                 ans = mid;
                 end = mid-1;
            }
            else start = mid + 1;
         }
         return ans;
    }
    int fun(vector<int>&nums,int &mid){
         int count = 0;
         int i = 0;
         int j = 0;
         while(j < nums.size()){
            if(i == j) j++;
          
                 if((nums[j] - nums[i]) <= mid){
                      //cout<<"mid = "<<mid<<" "<<"pair->"<<nums[i]<<":"<<nums[j]<<endl;
                      count = count + (j - (i+1) + 1);
                      j++;
                 }
                 else if((nums[j] - nums[i]) > mid){
                      i++;
                 }
         }

         return count;
    }
    
};