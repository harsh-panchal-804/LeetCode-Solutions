class Solution {
public:
    int maxScore(string s) {
        int maxval=0;
        int leftzero=0;
        int rightone=count(s.begin(),s.end(),'1');
        for(int i=0;i<s.size()-1;++i){
            if(s[i]=='0') leftzero++;
            else rightone--;
            maxval=max(maxval,leftzero+rightone);
        }
        return maxval;

        
    }
};