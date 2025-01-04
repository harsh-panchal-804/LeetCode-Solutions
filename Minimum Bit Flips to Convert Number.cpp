class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<31> x(start);
        bitset<31> y(goal);
        int ans=0;
        for(int i=0;i<=31;i++){
            if(x[i]!=y[i])ans++;
        }
        return ans;
    }
};