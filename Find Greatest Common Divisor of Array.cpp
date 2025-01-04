class Solution {
public:
    int findGCD(vector<int>& nums) {
        int m=*min_element(nums.begin(),nums.end());
        int x=*max_element(nums.begin(),nums.end());
        return __gcd(m,x);
    }
};