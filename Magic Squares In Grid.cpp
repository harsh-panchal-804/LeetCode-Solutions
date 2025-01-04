class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows-3+1;i+=1){
            for(int j=0;j<cols-3+1;j+=1){
                //borders are (i,j) (i+3-1,j+3-1)
                bool flag=true;
                int sum=0;
                for(int y=j;y<=j+2;y++){
                    if(grid[i][y]>9 || grid[i][y]<1)flag=false;
                    sum+=grid[i][y];
                }
                int a=0;
                for(int y=j;y<=j+2;y++){
                    if(grid[i+1][y]>9 || grid[i+1][y]<1)flag=false;
                    a+=grid[i+1][y];
                }
                flag&=(a==sum);
                int b=0;
                for(int y=j;y<=j+2;y++){
                    if(grid[i+2][y]>9 || grid[i+2][y]<1)flag=false;
                    b+=grid[i+2][y];
                }
                flag&=(b==sum);
                /// check col
                int p=0;
                for(int x=i;x<=i+2;x++){
                    if(grid[x][j]>9 ||grid[x][j]<1)flag=false;
                    p+=grid[x][j];
                }
                flag&=(p==sum);

                int q=0;
                for(int x=i;x<=i+2;x++){
                    if(grid[x][j+1]>9 ||grid[x][j+1]<1)flag=false;
                    q+=grid[x][j+1];
                }
                flag&=(q==sum);
                int r=0;
                for(int x=i;x<=i+2;x++){
                    if(grid[x][j+2]>9 ||grid[x][j+2]<1)flag=false;
                    r+=grid[x][j+2];
                }
                flag&=(r==sum);
                int u=0;
                for(int t=0;t<=2;t++){
                    u+=grid[i+t][j+t];
                }
                flag&=(u==sum);
                int v=0;
                for(int t=0;t<=2;t++){
                    v+=grid[i+t][j+2-t];
                }
                flag&=(v==sum);
                unordered_set<int> set;
                for(int x=i;x<=i+2;x++){
                    for(int y=j;y<=j+2;y++){
                        set.insert(grid[x][y]);
                    }
                }
                flag&=(set.size()>1);
                if(flag)ans++;
            }
        }
        return ans;
        



    }
};