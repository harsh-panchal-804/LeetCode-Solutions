class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int l=0;
        int r=tokens.size()-1;
        int score=0;
        int ans=0;
        sort(tokens.begin(),tokens.end());
        while(l<=r){
            if(power>=tokens[l]){
                power-=tokens[l];
                l++;
                score++;
                ans=max(ans,score);
            }
            else if(score>0){
                power+=tokens[r];
                r--;
                score--;
               
            }
            else{
                return 0;
            }
        }
        return ans;
        
    }
};