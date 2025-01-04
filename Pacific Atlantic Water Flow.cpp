class Solution {
public:
    vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> temp=heights;
        set<pair<int,int>>atlantic;
        queue<pair<int,int>> queue;
        vector<vector<int>> visp(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>> visa(heights.size(),vector<int>(heights[0].size(),0));
        for(int c=0;c<heights[0].size();c++){
            queue.push({heights.size()-1,c});
            
        }
        for(int r=0;r<heights.size();r++){
            queue.push({r,heights[0].size()-1});
         
        }
        // atlantic
        while(!queue.empty()){
            int r=queue.front().first;
            int c=queue.front().second;
            visa[r][c]=1;
            atlantic.insert({r,c});
            queue.pop();
           
            for(auto dir : dirs){
                int x=r+dir.first;
                int y=c+dir.second;
                if(x>=0 && y>=0&&x<heights.size()&&y<heights[0].size()&& heights[x][y]>=heights[r][c]&& visa[x][y]==0){
                    queue.push({x,y});
                    
             
                }
            }
            
        }
        // heights=temp;
        set<pair<int,int>> pacific;
        ///queue.clear();
        for(int r=0;r<heights.size();r++){
            queue.push({r,0});
        }
        for(int c=0;c<heights[0].size();c++){
            queue.push({0,c});
        }
        while(!queue.empty()){
            int r=queue.front().first;
            int c=queue.front().second;
            visp[r][c]=1;
            atlantic.insert({r,c});
            queue.pop();
           
            for(auto dir : dirs){
                int x=r+dir.first;
                int y=c+dir.second;
                if(x>=0 && y>=0&&x<heights.size()&&y<heights[0].size()&& heights[x][y]>=heights[r][c]&& visp[x][y]==0){
                    queue.push({x,y});
                    
             
                }
            }
            
        }
        vector<vector<int>> ans;
        // for(auto i : atlantic){
        //     if(pacific.count(i)>0){
        //         ans.push_back({i.first,i.second});
        //     }
        // }
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                
                if(visp[i][j]==1 && visa[i][j]==1)
                    ans.push_back({i,j});
            }
        }

        for(auto i : atlantic){
            cout<<i.first<<" "<<i.second<<endl;
        }
        cout<<endl;
        for(auto i : pacific){
            cout<<i.first<<" "<<i.second<<endl;
        }
        return ans;
        
    }
};