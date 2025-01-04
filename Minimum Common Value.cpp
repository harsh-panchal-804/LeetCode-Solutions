class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec(nums1.size()+nums2.size(),-1);
        vector<int>:: iterator a,b;
        a=set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),vec.begin());    

        return *vec.begin();
    }
};