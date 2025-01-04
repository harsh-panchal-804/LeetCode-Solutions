class Solution {
public:
    bool dfs(vector<vector<char>> &board,int r,int c,int i,string &word){
        if(i>=word.size()){
            return true;
        }
        if(r<0 || c<0 || r >=board.size() || c>=board[0].size() || board[r][c] != word[i] || board[r][c]=='.'){
            return false;
        }
        char ch=board[r][c];
        board[r][c]='.';
        bool ans=(dfs(board,r,c+1,i+1,word) ||dfs(board,r,c-1,i+1,word) || dfs(board,r+1,c,i+1,word) || dfs(board,r-1,c,i+1,word));
        board[r][c]=ch;
        return ans;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
       
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(dfs(board,r,c,0,word)) return true;
            }
        }
        return false;
        
        
    }
};