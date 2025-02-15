class Solution {
public:
    int trapRainWater(vector<vector<int>>& heights) {
        vector<pair<int,int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        int m=heights.size();
        int n=heights[0].size();
        map<pair<int,int>,bool> vis;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    pq.push({heights[i][j],i,j});
                    vis[{i,j}]=true;
                }
            }
        }
        int ans=0;
        while(!pq.empty()){
            auto [height,x,y]=pq.top();
            pq.pop();
            // if(vis[{x,y}])continue;
            for(auto dir : dirs){
                int nx=x+dir.first;
                int ny=y+dir.second;
                if(nx>=0 && ny>=0 && nx<m && ny<n && !vis[{nx,ny}]){
                    vis[{nx,ny}]= true;
                    
                    ans += max(0, height - heights[nx][ny]);

                    pq.push({max(height, heights[nx][ny]), nx, ny});
                }
            }
        }
        return ans;
    }
};