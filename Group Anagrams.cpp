class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> map;
        for(auto word: strs){
            vector<int> letvec(26,0);
            for(auto ch:word){
                letvec[ch-'a']++;
            }
           map[letvec].push_back(word);
          
        }
        
        vector<vector<string>> fans;
         for(auto i: map){
            fans.push_back(i.second);
            }
        return fans;

    }

        
    
};