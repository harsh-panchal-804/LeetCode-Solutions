class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        function<void(int)> dfs=[&](int curr){
            if(curr<=n)ans.push_back(curr);
            for(int i=0;i<=9;i++){
                int next=10*curr+i;
                if(next<=n){
                    dfs(next);
                }
            }
        };
        for(int i=1;i<=9;i++){
            dfs(i);
        }
        return ans;

        
    }
};