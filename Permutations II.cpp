class Solution {
public:
    void perm(vector<int>&nums,vector<vector<int>>&fans, int i){
        if(i==nums.size()-1){
            fans.push_back(nums);
            return ;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[j],nums[i]);
            perm(nums,fans,i+1);
            swap(nums[i],nums[j]);
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>fans;
        perm(nums,fans,0);
        set<vector<int>> set;
        for(auto i:fans){
            set.insert(i);
        }
        fans.clear();
        for(auto i: set){
            fans.push_back(i);
        }

        return fans;

        
    }
};