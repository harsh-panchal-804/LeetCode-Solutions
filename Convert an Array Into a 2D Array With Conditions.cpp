class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<vector<int>> fans;
        for(auto i: nums){
            int row=map[i];
            if(row==fans.size()){
                vector<int> vec;
                fans.push_back(vec);
            }
            fans[row].push_back(i);
            map[i]++;
        }
        return fans;


        
    }
};