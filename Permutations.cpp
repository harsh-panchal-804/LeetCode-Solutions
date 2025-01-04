class Solution {

public:
    void solve(vector<int> nums, vector<vector<int>> &fans,int index){
        if(index>=nums.size()){
            fans.push_back(nums);
            return ;
        }
        for(int j=index;j<nums.size();j++){
            swap(nums[index],nums[j]);
            solve(nums,fans,index+1);
            swap(nums[index],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> fans;
        solve(nums,fans,0);
        return fans;

    }
};