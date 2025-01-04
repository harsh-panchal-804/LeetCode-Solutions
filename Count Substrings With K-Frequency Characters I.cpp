class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int count=0;
        auto func=[&](int x){
            return x>=k;
        };
        for(int i=0;i<s.size();i++){
            vector<int> frq(26,0);
            for(int j=i;j<s.size();j++){
                frq[s[j]-'a']++;
                if(any_of(frq.begin(),frq.end(),func)){
                    count++;
                }
                
            }
        }
        return count;
    }
};