class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> adj;
        map<vector<int>,int> map;
        int n=points.size();
        for(int i=0;i<n;i++){
            map[points[i]]=i;
            for(int j=i+1;j<n;j++){
                int a = points[i][0];
                int b = points[i][1];
                int c = points[j][0];
                int d = points[j][1];
                int dist=abs(a-c)+abs(b-d);
                adj.push_back({dist,a,b,c,d});
            }
        }
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
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq(adj.begin(),adj.end());
        for(int i=0;i<n;i++)make(i);
        int ans=0;
        n--;
        while(n && !pq.empty()){
            auto v = pq.top();
            pq.pop();
            int dist = v[0];
            int a = v[1];
            int b = v[2];
            int c = v[3];
            int d = v[4];
            if(find(map[{a,b}])==find(map[{c,d}]))continue;
            ans+=dist;
            Union(map[{a,b}],map[{c,d}]);
            n--;
        
        }
        return ans;
         
        
    }
};