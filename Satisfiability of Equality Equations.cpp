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
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(2e3);
        vector<int> size(2e3);
        for(int i=0;i<26;i++){
            make(i,parent,size);
        }
        // sort(equations.begin(),equations.end(),[](string &a,string &b){
        //     if(a[1]=='='){
        //         return true;
        //     }
        //     else return false;
        // });
        // for(auto i : equations){
        //     cout<<i<<" ";
        // }
        for(auto &i : equations){
            if(i[1]=='=') Union(i[0]-'a',i[3]-'a',parent,size);
        
        }
        for(auto &i : equations){
            if(i[1]=='!'){
                if(find(i[0]-'a',parent)==find(i[3]-'a',parent)){
                    return false;
                }
            }
        }
        return true;
        
    }
};