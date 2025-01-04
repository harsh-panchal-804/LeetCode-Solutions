class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto i : nums){
            map[i]++;
        }
        int count=0;
        for(auto i : map){
            if(k==0){
                if(i.second>=2){
                    count++;
                }
            }
            else if(map.contains(i.first+k)){
                count++;
            }
        }
        return count;
        
    }
};