class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int maxd=-1;
        int maxind=-1;
        int minind=-1;
        int rind=-1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]>maxd){
                maxd=s[i];
                maxind=i;
            }
            if(s[i]<maxd){
                minind=i;
                rind=maxind;

            }
        }
        if(minind==-1)return num;
        swap(s[minind],s[rind]);
        return stoi(s);
        
    }
};