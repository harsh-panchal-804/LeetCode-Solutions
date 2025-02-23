class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long  n=weights.size();
        vector<long long > pairs(n-1,0);
        for(long long  i=1;i<n;i++){
            pairs[i-1] += weights[i]  + weights[i-1];
        }   
        sort(pairs.begin(),pairs.end());
        long long  ans=0;
        for(long long  i=0;i<k-1;i++){
            ans += pairs[n-2-i] -pairs[i];
        }
        return ans;
    }
};