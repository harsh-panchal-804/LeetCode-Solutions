class Solution {
public:
    int ans=0;
    bool check(unordered_map<char,int>&lettercount,string word){
        for(auto i : word){
            if(count(word.begin(),word.end(),i)>lettercount[i]){
                return false;
            }
        }
        return true;
    }
    void dfs(int i,vector<string>&words,unordered_map<string,int>&wordmap,int tscore,unordered_map<char,int>&lettercount){
        if(i>=words.size()){
            ans=max(ans,tscore);
            return;
        }
        //include
        if(check(lettercount,words[i])){
            ///tscore+=wordmap[words[i]];
            cout<<"SELECTED "<<words[i]<<endl; 
            for(auto i: words[i]){
                lettercount[i]--;
            }
            dfs(i+1,words,wordmap,tscore+wordmap[words[i]],lettercount);
            for(auto i: words[i]){
                lettercount[i]++;
            }
            ///tscore-=wordmap[words[i]];
        }
        dfs(i+1,words,wordmap,tscore,lettercount);


    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int> lettermap;
        unordered_map<char,int> lettercount;

        for(int i=0;i<26;i++){
            lettermap['a'+i]=score[i];
        }
        for(auto i : letters){
            lettercount[i]++;
        }
        unordered_map<string,int> wordmap;
        for(int i=0;i<words.size();i++){
            int s=0;
            for(auto ch: words[i]){
                s+=lettermap[ch];
            }
            wordmap[words[i]]=s;
            cout<<words[i]<<s<<" "<<endl;
        }
        int tscore=0;
        dfs(0,words,wordmap,tscore,lettercount);
        return ans;
        

        
    }
};