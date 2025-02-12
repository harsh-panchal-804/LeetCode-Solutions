class Solution {
public:
    bool dist(string & a,string &b){
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return false; 
        }
    }
    return diff == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,vector<string>> graph;

        if(!count(wordList.begin(),wordList.end(),beginWord))wordList.push_back(beginWord);
        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                if(dist(wordList[i],wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        for(auto i : graph){
            cout<<i.first<<" ";
            for(auto j : i.second)cout<<j<<' ';
            cout<<"\n";
        }
        queue<pair<string,int>> queue;
        unordered_map<string,bool> vis;
        queue.push({beginWord,1});
        while(!queue.empty()){
            auto [node,lvl]=queue.front();
            queue.pop();
            // cout<<node<<"\n";
            if(node==endWord)return lvl;
            vis[node]=true;
            for(auto child : graph[node]){
                if(vis[child]==true)continue;
                queue.push({child,lvl+1});
            }
        }
        return 0;
    }
};