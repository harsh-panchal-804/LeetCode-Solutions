class Solution {
public:
    vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> vec=board;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int livecount=0;
                for(auto &dir : dirs){
                    int x=i+dir.first;
                    int y=j+dir.second;
                    if(x>=0 && y>=0 && x<m &&y<n){
                        if(vec[x][y]==1)livecount++;
                    }
                }
                if(vec[i][j]==1){
                    if(livecount<2){
                        board[i][j]=0;
                    }
                    else if(livecount==2 || livecount==3){
                        board[i][j]=1;
                    }
                    else{
                        board[i][j]=0;
                    }
                }
                else{
                    if(livecount==3){
                        board[i][j]=1;
                    }
                }

            }
        }
      

        
    }
};