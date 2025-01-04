class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int hash[256] = {0};
        int count = 0;
        for(int i = 0;i<stones.size();i++) {
            hash[stones[i]]++;
        }
        for(int i = 0;i<jewels.size();i++) {
            count = count + hash[jewels[i]];
        }
        return count;
    }
};