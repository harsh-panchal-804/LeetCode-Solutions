class TrieNode{
    public:
    bool end;
    vector<TrieNode*> children;
    TrieNode(){
        this->end=false;
        this->children.resize(26,nullptr);
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        this->root=new TrieNode();
    }
    void insert(string &a ){
        TrieNode* curr=root;
        for(auto ch : a){
            if(curr->children[ch-'a']==nullptr){
                curr->children[ch-'a']=new TrieNode();
            }
            curr=curr->children[ch-'a'];
        }
        curr->end=true;
    }
    bool isPrefix(string & a){
        TrieNode* curr=root;
        for(auto ch : a){
            if(curr->children[ch-'a']==nullptr){
                return false;
            }
            curr=curr->children[ch-'a'];
        }
        return true;
    }
};


class Solution {
public:
    Trie trie;
    int m,n;
    vector<string> ans;
    unordered_set<string> st;
    void dfs(int x,int y,string word,vector<vector<char>>& board){
        if(x<0 || y<0 || x>=m || y>=n)return;
        if(board[x][y]=='*')return;
        char c=board[x][y];
        word.push_back(c);
        if(trie.isPrefix(word)==false)return;
        if(st.count(word)){
            ans.push_back(word);
            st.erase(word);
            // return;
        }
       
        board[x][y]='*';
        dfs(x+1,y,word,board);
        dfs(x-1,y,word,board);
        dfs(x,y+1,word,board);
        dfs(x,y-1,word,board);
        board[x][y]=c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        st=unordered_set<string>(words.begin(),words.end());
        for(auto word:words){
            trie.insert(word);
        }
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               
                dfs(i,j,"",board);
                
            }
        }
        return ans;
    }
};