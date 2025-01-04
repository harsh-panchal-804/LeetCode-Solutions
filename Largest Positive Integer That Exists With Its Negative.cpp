class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> map;
        int ans=-1;
        for(auto i : nums){
            map[i]++;
            int j=i*-1;
            if(map[j]>0){
                ans=max(ans,abs(i));
            }
        }


        
        return ans;
    }
};