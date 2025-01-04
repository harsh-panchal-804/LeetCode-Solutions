class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int req=requests.size();
        int fmask=(1<<req)-1;
        int ans=0;
        for(int mask=0;mask<=fmask;mask++){
            vector<int> indegree(21,0);
            for(int i=31;i>=0;i--){
                if(mask&(1<<i)){
                    indegree[requests[i][0]]++;
                    indegree[requests[i][1]]--;
                }
            }
            bool flag=any_of(indegree.begin(),indegree.end(),[&](int x){
                return x!=0;
            });
            if(!flag){
                ans=max(ans,__builtin_popcount(mask));
            }
        }
        return ans;

    }
};