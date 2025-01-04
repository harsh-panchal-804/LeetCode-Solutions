class Solution {
public:
    vector<int> frequency(string& s){
        vector<int> f(26,0);
        for(auto c: s){
            f[c-'a']++;
        }
        return f;
    }
    bool check(vector<int> freq,vector<int> chars){
        for(int i=0;i<26;i++){
            if(freq[i]>chars[i]) return 0;
        }
        return 1;
    }

    int countCharacters(vector<string>& words, string chars) {
        vector<int> ch=frequency(chars);
        int ans=0;
        for(auto s: words){
            if(check(frequency(s),ch)){
                ans+=s.size();
            }
        }
        return ans;
        
    }
};