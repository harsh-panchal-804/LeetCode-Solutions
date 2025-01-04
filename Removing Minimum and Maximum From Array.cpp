class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int a=min_element(nums.begin(),nums.end())-nums.begin();
        int b=max_element(nums.begin(),nums.end())-nums.begin();
        int l=max(a+1,b+1);
        int r=max(nums.size()-a,nums.size()-b);
        a=min((int)a+1,(int)nums.size()-a);
        b=min((int)b+1,(int)nums.size()-b);
        int c=a+b;
        return min({l,r,c});
        
        
    }
};
///1  5