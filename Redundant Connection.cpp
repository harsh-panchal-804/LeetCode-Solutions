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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> parent(2e3);
        vector<int> size(2e3);
        int n=edges.size();

        for(int i=1;i<=n;i++){
            make(i,parent,size);
        }
        for(auto &i : edges){
            int u=i[0];
            int v=i[1];
            if(find(u,parent)==find(v,parent)){
                ans=i;
                continue;
            }
            else{
                Union(u,v,parent,size);
            }
        }
        return ans;
        
    }
};