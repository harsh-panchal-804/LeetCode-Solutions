class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {

        vector<int> parent(n);
        vector<int> size(n);
        auto make=[&](int i){
            parent[i]=i;
            size[i]=1;
        };
        function<int(int)> find=[&](int a){
            if(parent[a]==a)return a;
            return parent[a]=find(parent[a]);
        };
        auto Union=[&](int a,int b){
            a=find(a);
            b=find(b);
            if(a!=b){
                if(size[a]<size[b])swap(a,b);
                parent[b]=a;
                size[a]+=size[b];
            }
        };
        for(int i=0;i<n;i++)make(i);

        vector<int> indegree(n,0);
        int redundant=0;
        for(auto & i : edges){
            int u=i[0];
            int v=i[1];
            indegree[u]++;
            indegree[v]++;
            if(find(u)==find(v))redundant++;
            Union(u,v);
        }
        int null=count(indegree.begin(),indegree.end(),0);
        ///cout<<null<<"  "<<redundant;
      
        int comps=0;
        for(int i=0;i<n;i++)if(i==parent[i])comps++;
        if(redundant>=comps-1)return comps-1;
        else return -1;
        
        
    }
};