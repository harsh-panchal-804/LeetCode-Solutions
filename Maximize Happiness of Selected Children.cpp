class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long int sum=0;
        int minus=0;
        for(int i=0;i<k;i++){
            if(happiness[i]-minus>0) sum+=(happiness[i]-minus);

            minus++;
        }
        
        return sum;
        
    }
    // 3 2 1 
    // 5 3 2 1
    ///37 22q
    /// 83 
};