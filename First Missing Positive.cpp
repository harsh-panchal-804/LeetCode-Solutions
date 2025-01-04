class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int fi=1;
        unordered_map<int,int> map;
        for(auto i : nums){
            map[i]=1;
        }
        ///reverse(nums.begin(),nums.end());
        while(true){
            if(map.count(fi)>0){
            fi++;
            }
            else return fi;     
        }
    }
};