class Solution {
public:
    int climbStairs(int n) {
        int one_back=1;
        int two_back=1;
        int total;
        if(n==1) return 1;
       

        for(int i =2;i<=n;i++){
            total=one_back+two_back;
            two_back=one_back;
            one_back=total;

        }
        return total;

        
    }
};