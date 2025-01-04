class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        long long maxNum=0;
    sort(nums.begin(), nums.end());
    do {
      
        string binaryConcat = "";
        for (int num : nums) {
           
            binaryConcat += bitset<32>(num).to_string().substr(bitset<32>(num).to_string().find('1'));
        }
        
      
        long long numValue = stoll(binaryConcat, nullptr, 2);

       
        maxNum = max(maxNum, numValue);

    } while (next_permutation(nums.begin(), nums.end()));

    return maxNum;
    }
};