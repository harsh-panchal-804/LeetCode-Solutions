class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> fans;
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();i++){
            int left=i+1;
            int right=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]) continue ;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum>0){
                    right--;
                }
                else if (sum<0){
                    left++;
                }
                else if(sum==0){
                    ans.push_back(nums[i]);
                    ans.push_back(nums[left]);
                    ans.push_back(nums[right]);
                    fans.push_back(ans);
                    ans.clear();
                    left++;
                    while(nums[left]==nums[left-1] && left<right){
                        left++;
                    }
                   
                }       
            }
        }
        return fans;
        
    }
};