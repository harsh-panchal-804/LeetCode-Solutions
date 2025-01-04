class Solution {
public:
    int numWaterBottles(int a, int b) {
        return a+ (a-1)/(b-1) ;
        
    }
};