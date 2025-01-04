class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> map;
        vector<string> ans;
        int size=s.size();
        for(int i=0;i<size-9;i++){
            map[s.substr(i,10)]++;
        }
        for(auto it=map.begin();it!=map.end();it++){
            if(it->second>1) ans.push_back(it->first);
        }
        return ans;
        
    }
};