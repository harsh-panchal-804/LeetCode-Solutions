
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> ans;
        for(auto i : nums){
            if(map.count(i)){
                ans.push_back(i);
            }
            map[i]++;
        }
        return ans;
    }
};