class Solution {
public:
    void dfs(int sr,int sc,int color,vector<vector<int>>& image,int og){
        if(sr<0||sc<0||sr>=image.size()||sc>=image[0].size()||(image[sr][sc]!=og)){
            return;
        }
        image[sr][sc]=color;
        dfs(sr,sc+1,color,image,og);
        dfs(sr,sc-1,color,image,og);
        dfs(sr+1,sc,color,image,og);
        dfs(sr-1,sc,color,image,og);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {      
        int og=image[sr][sc];
        if(image[sr][sc]==color)return image;
        dfs(sr,sc,color,image,og);
        return image;
        
    }
};