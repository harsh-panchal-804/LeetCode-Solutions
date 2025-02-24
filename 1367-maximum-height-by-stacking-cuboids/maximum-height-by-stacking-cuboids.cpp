class Solution {
public:
    int dfs(int i ,vector<vector<int>>& cuboids,int prev){
        if(i>=cuboids.size())return 0;
        /// take or not
        int op1=dfs(i+1,cuboids,prev);
        int op2=0;
        if(prev==-1 || (cuboids[prev][0]<=cuboids[i][0] && cuboids[prev][1]<=cuboids[i][1] && cuboids[prev][2]<=cuboids[i][2])){
            op2=cuboids[i][2] + dfs(i+1,cuboids,i);
        }
        return max(op1,op2);
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto & c: cuboids){
            sort(c.begin(),c.end());
        }
        sort(cuboids.begin(),cuboids.end());
        int ans=dfs(0,cuboids,-1);
        return ans;
    }
};