class Solution {
public:
    void make(int i,vector<int>&parent,vector<int>&size){

        parent[i]=i;
        size[i]=1;
    }
    int find(int x,vector<int>&parent){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x],parent);
    }
    void Union(int a,int b,vector<int>&parent,vector<int>&size){
        a=find(a,parent);
        b=find(b,parent);
        if(a!=b){
            if(size[a]<size[b]){
                swap(a,b);
            }
            parent[b]=a;
            size[a]+=size[b];
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> parent(2e3);
        vector<int> size(2e3);
        int n=graph.size();
        for(int i=0;i<n;i++)make(i,parent,size);
        for(int i=0;i<n;i++){
            if(graph[i].size()){
            int first=graph[i][0];
            for(auto u : graph[i]){
                if(find(i,parent)==find(u,parent)){
                    return false;
                }
                Union(u,first,parent,size);
            }
            }
        }
        return true;
        
    }
};