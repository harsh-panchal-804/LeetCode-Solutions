class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> set(nums.begin(),nums.end());
        int ans=1;
        unordered_set<long long> :: iterator itr;
        for(itr=set.begin();itr!=set.end();itr++){
            long long first=*itr;
            int temp=1;
            while(set.find(1ll*first*first)!=set.end()){
                temp++;
                first*=first;
            }
            ans=max(ans,temp);
        }
        return ans>=2? ans:-1;
    }
};