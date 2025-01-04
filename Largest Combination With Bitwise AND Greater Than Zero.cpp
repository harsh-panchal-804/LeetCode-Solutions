class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bits(31,0);
        for(auto num:candidates){
            int temp=num;
            for(int i=31;i>=0;i--){
                if(temp&(1<<i))bits[i]++;
            }
        }
        return *max_element(bits.begin(),bits.end());
    }
};