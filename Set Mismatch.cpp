class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup=0;
        int mis=0;
       
        vector<int> map(nums.size()+1,0);
        
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(int i=1;i<map.size();i++){
            if(map[i]==2) dup=i;
            if(map[i]==0) mis=i;
        }
        return {dup,mis};
        
    }
};