class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> maps,mapt;
        /// check transformations s->t and t->s
        for(int i=0;i<s.size();i++){
            if((maps[s[i]]&& maps[s[i]]!=t[i]) || (mapt[t[i]]&& mapt[t[i]]!=s[i])){
                return false;
            }
            maps[s[i]]=t[i];
            mapt[t[i]]=s[i];
        }
        return true;

    }
};