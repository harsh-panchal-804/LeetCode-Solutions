class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        bool sign =(dividend>=0)==(divisor>=0)? true:false;
        long dvd=abs(dividend);
        long div=abs(divisor);

        long result=0;
        while(dvd>=div){
            int count=0;
            while(dvd-(div<<1<<count)>=0){
                count++;
            }
            result+=1<<count ;
            dvd-=div<<count;
        }
    return sign? result : -result;
    }
};