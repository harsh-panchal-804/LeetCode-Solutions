class Solution {
public:
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
        int n=A.size();
        long long sum_a=0;
        long long sum_b=0;
        for(int i=0;i<n;i++){
            long long new_a=max(sum_a+A[i],sum_b);
            long long new_b=max(sum_b+B[i],sum_a);
            sum_a=new_a;
            sum_b=new_b;
        }
        return max(sum_a,sum_b);
        
    }
};