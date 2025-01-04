class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
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
        for(auto & i : edges){
            int u=i[0];
            int v=i[1];
            Union(u,v);
        }
        long count=0;
        for(int i=0;i<n;i++){
            int a=find(i);
            count+= (n-size[a]);
        }
        return count/2;
        
    }
};