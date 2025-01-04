class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s =to_string(n);
        int l=s.size();
        for(int i=s.size()-1;i>0;i--){
            if(s[i]<s[i-1]){
                l=i;
                s[i-1]--;
            }
        }
        for(int i=l;i<s.size();i++){
            s[i]='9';
        }
        return stoi(s);
        
    }
};