class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right)return left;
        if(left<=right/2)return 0;
        long long int a=left;
        for(long long int i=left+1;i<=right;i++){
           a =a&i;
        }
        return a;
        
    }
};
/// 1 0 0
/// 0 0 0