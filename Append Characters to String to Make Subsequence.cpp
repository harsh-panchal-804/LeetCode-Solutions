class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans=0;
        int i=0;
        int j=0;
        while(i<s.size()&&j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
                ///ans=max(ans,j-i+1);
            }
            else{
                i++;
            }
        }
        return t.size()-j;


        
    }
};