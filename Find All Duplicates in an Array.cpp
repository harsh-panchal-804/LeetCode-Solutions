class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> vec;
        for(auto i: nums){
            map[i]++;
            if(map[i]>1) vec.push_back(i);
        }
        return vec;
        
    }
};