class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> psign(26,0);
        if(s.size() < p.size()) return {};
        for(auto i:p){
            psign[i-'a']++;
        }
        vector<int> ssign(26,0);
        for(int i=0;i<p.size();i++){
            ssign[s[i]-'a']++;
        }
        vector<int> ans;
        if(ssign==psign) ans.push_back(0);
        for(int i=p.size();i<s.size();i++){
            ssign[s[i]-'a']++;
            ssign[s[i-p.size()]-'a']--;
            if(ssign==psign) ans.push_back(i-p.size()+1);

        }
        return ans;



        
    }
};