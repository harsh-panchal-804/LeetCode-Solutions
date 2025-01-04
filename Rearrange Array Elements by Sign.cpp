class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> vec1;
        vector<int> vec2;
        for(auto i : nums){
            if(i>=0 ) vec1.push_back(i);
            else vec2.push_back(i);
        }
        int i=0;
        vector<int> num;
        while(i<nums.size()/2){
            num.push_back(vec1[i]);
            num.push_back(vec2[i]);
            i++;
        }
        return num;

        
    }
};