class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        string str;
        vector<string> words;
        while(getline(ss,str,' ')){
            words.push_back(str);
        }
        for(auto &word: words){
            for(auto &dic:dictionary){
                if(dic.size()<=word.size() && dic==word.substr(0,dic.size())){
                    word=dic;
                }
            }
        }
        string ans="";
        for(auto i: words){
           ans+=i;
           ans+=' ';
        }
        ans.pop_back();
        return ans;
        
    }
};