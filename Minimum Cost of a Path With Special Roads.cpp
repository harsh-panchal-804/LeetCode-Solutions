class Solution {
public:
    int cost(int x1, int y1, int x2, int y2){
        return abs(x1-x2) + abs(y1-y2);
    }
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& roads) {
        map<pair<int,int> , int>mp;
        mp[{start[0],start[1]}] = 0;
        vector<pair<int,int>>g[504];
        int cnt = 1;
        for(auto road : roads){
            int x1 = road[0], y1 = road[1];
            int x2 = road[2], y2 = road[3];
            if(mp.find({x1,y1}) == mp.end()){
                mp[{x1,y1}] = cnt;
                cnt++;
            }
            if(mp.find({x2,y2}) == mp.end()){
                mp[{x2,y2}] = cnt;
                cnt++;
            }
        }
        if(mp.find({target[0],target[1]}) == mp.end()){
            mp[{target[0],target[1]}] = cnt;
            cnt++;
        } 
        // cout<<cnt<<endl;
    
        int tar = mp[{target[0],target[1]}];
        for(auto road : roads){
            int x1 = road[0], y1 = road[1];
            int x2 = road[2], y2 = road[3];
            int c = road[4];
            int u = mp[{x1,y1}];
            int v = mp[{x2,y2}];
            g[0].push_back({u,cost(start[0],start[1],x1,y1)});
            g[u].push_back({v,c});
            g[v].push_back({tar, cost(x2,y2,target[0],target[1])});
            for(auto r : roads){
                int xi = r[0], yi = r[1];
                int xj = r[2], yj = r[3];
                int pt1 = mp[{xi,yi}];
                int pt2 = mp[{xj,yj}];
                if(pt1 != u) g[pt1].push_back({u,cost(xi,yi,x1,y1)});
                if(pt1 != v) g[pt1].push_back({v,cost(xi,yi,x2,y2)});
                if(pt2 != u) g[pt2].push_back({u,cost(xj,yj,x1,y1)});
                if(pt2 != v) g[pt2].push_back({v,cost(xj,yj,x2,y2)});
            }
        }
        g[0].push_back({tar,cost(start[0],start[1],target[0],target[1])});


        vector<int>minDist(cnt,INT_MAX);
        minDist[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});

        while(!pq.empty()){
            int dist = pq.top().first;
            int pt = pq.top().second;
            pq.pop();

            for(auto p : g[pt]){
                int node = p.first;
                int c = p.second;
                if(dist + c < minDist[node]){
                    minDist[node] = dist + c;
                    pq.push({dist+c,node});
                }
            }
        }
        
        return minDist[tar];
    
    }
};