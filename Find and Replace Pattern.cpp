class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        set<char> set2(pattern.begin(),pattern.end());
        for(auto word:words){
            unordered_map<char,char>map;
            bool flag=true;
            for(int i=0;i<word.size();i++){
                if(map.contains(word[i])&&map[word[i]]!=pattern[i]){
                    flag=false;
                    break;
                }
                else {
                    map[word[i]]=pattern[i];
                }
                set<char> set1(word.begin(),word.end());
                flag=(set1.size()==set2.size());
            }
            if(flag)ans.push_back(word);

        }
        return ans;
        
    }
};