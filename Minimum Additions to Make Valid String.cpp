class Solution {
public:
    int addMinimum(string word) {
        string s="abc";
        int x=0;
        int y=0;
        int ans=0;
        int n=word.size();
        while(x<word.size()){
            if(word[x]!=s[y]){
                ans++;
                y++;
            }
            else{
                x++;
                y++;
            }
            y%=3;
        }
        if(word[n-1] == 'a') return ans + 2;
        if(word[n-1] == 'b') return ans + 1;
        return ans;
        
    }
};