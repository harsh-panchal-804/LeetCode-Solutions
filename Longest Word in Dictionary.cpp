class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> set;
        sort(words.begin(),words.end());
        string ans="";
        for(int i=0;i<words.size();i++){
            string st=words[i];
            if(st.size()==1||set.count(st.substr(0,st.size()-1))){
                if(st.size()>ans.size())ans=st;
                set.insert(st);
            }
            
        }
        return ans;
    }
};