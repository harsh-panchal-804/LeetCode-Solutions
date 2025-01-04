class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> map;
        for(auto i: nums) map[i]++;
        nums.clear();
        vector<int> color={0,1,2};
        for(int c: color){
            for(int i=0;i<map[c];i++){
                nums.push_back(c);
            }
        }
        
    }
};