class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> f1(26,0);
        vector<int> f2(26,0);
        for(auto i : word1){
            f1[i-'a']++;
        }
        for(auto i : word2){
            f2[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(f1[i]==0 && f2[i]!=0 ||(f1[i]!=0 && f2[i]==0)){
                return false;
            }
        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        return f1==f2;

        
    }
};