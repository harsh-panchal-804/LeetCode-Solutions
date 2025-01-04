class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> map;
        for(auto i : nums){
            map[i]++;
            if(map[i]>1) return true;
        }
        return false;
        
    }
};