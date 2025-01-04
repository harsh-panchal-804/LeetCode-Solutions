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
    int findCircleNum(vector<vector<int>>& iscon) {
        vector<int> parent(2e3);
        vector<int> size(2e3);
        int ans=0;
        for(int i=1;i<=iscon.size();i++){
            make(i,parent,size);
        }
        for(int i=0;i<iscon.size();i++){
            for(int j=0;j<iscon.size();j++){
                if(iscon[i][j]==1){
                    Union(i+1,j+1,parent,size);
                }
            }
        }
        const int n=2e2+50;
        for(int i=1;i<=n;i++){
            if(i==parent[i])ans++;
        }
        return ans;

        
    }
};