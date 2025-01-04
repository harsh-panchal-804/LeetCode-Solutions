class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> map;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=0;j<nums[i].size();j++){
                map[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        int curr = 0;
        
        while (map.find(curr) != map.end()) {
            for (int num : map[curr]) {
                ans.push_back(num);
            }
            
            curr++;
        }
        
        return ans;
    }
};