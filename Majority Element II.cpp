class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto i: nums){
            map[i]++;
        }
        vector<int> ans;
        for(auto i: map){
            if(i.second>(nums.size()/3)){
                ans.push_back(i.first);
            }
        }
        return ans;
        
    }
};