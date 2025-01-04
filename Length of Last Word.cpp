class Solution {
public:
    int lengthOfLastWord(string s) {
        int right=s.size()-1;
        if(s.size()==1) return 1;
        while(s[right]==int(32) && right>0){
            right--;
        }
        if(right==0)  return 1;
        int left= right-1;
        while(s[left]!=int(32) && left>0){
            left--;
        }
        cout<<"right "<<right<<endl;
        cout<<"left " <<left<<endl;

        if(s[left]==int(32)) return right-left;
        else return right-left+1;

       

        
    }
};