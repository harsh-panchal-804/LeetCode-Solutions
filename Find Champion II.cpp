class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        for(auto & i : edges){
            int u=i[0];
            int v=i[1];
            indegree[v]++;
        }
        if(count(indegree.begin(),indegree.end(),0)>1)return -1;
        return min_element(indegree.begin(),indegree.end())-indegree.begin();
    }
};