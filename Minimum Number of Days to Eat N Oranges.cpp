class Solution {
public:
    unordered_map<int,int> map;
    int solve(int n){
        if(n==0)return 0;
        if(map.count(n))return map[n];
        int op1=1e8;
        int op2=1e8;
        int op3=1e8;
        if(n%2==0){
            op2=1+solve(n/2);
        }
        if(n%3==0){
            op3=1+solve(n/3);
        }
        if(n%2!=0 || n%3!=0){
            op1=1+solve(n-1);
        }
        return map[n]=min({op1,op2,op3});
    }
    int minDays(int n) {
        return solve(n);
    }
};