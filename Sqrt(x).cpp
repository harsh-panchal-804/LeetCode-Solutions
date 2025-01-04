class Solution {
public:
    int mySqrt(int x) {
        long long int left=1;
        long long int right=x;
        long long int mid;
        if(x==0){
            return x;
        }

        while(left<=right){
            mid=(int) (left +right)/2;
            if(mid<x/mid){
                left=mid+1;
            }
            else if (mid>x/mid){
                right=mid-1;
            }
            else{
                return mid;
            }
            
            
            }

        return right;
        
        
    }
};