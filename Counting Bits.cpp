class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            int count=0;
            int n=i;
            while(n){
                n=n&(n-1);
                ++count;
            }
            ans.push_back(count);
        }
        return ans;
        
    }
};