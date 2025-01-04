class Solution {
public:
    bool isSub(string s, string w){
        auto beg=0;
        for(auto c:w){
            int next=s.find(c,beg);
            if(s.find(c,beg)==string ::npos){
                return false;
            }
            else beg=next+1;
        }
        return true;
    }
    bool isSubsequence(string s, string t) {
        return isSub(t,s);
    }
};