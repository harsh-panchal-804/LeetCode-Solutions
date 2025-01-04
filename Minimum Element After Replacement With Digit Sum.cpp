class Solution {
public:
    int minElement(vector<int>& nums) {
        for(auto & i : nums){
            int temp=0;
            string x=to_string(i);
            for(auto &ch : x){
                temp+=ch-'0';
            }
            i=temp;
        }
        return *min_element(nums.begin(),nums.end());
    }
};