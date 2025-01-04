// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a =69;
        while(a>=40){
            a=7*(rand7()-1)+ (rand7()-1);
        }
       
        return 1+a%10;
        
        
    }
};