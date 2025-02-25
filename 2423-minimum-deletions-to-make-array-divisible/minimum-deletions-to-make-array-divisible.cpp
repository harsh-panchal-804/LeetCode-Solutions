class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd=numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            gcd=__gcd(gcd,numsDivide[i]);
        }
        map<int,int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        int ans=0;
        for(auto [num,freq]: mp){
            if(gcd % num ==0){
                return ans;
            }
            else{
                ans += freq;
            }
        }
        return -1;
    }
};