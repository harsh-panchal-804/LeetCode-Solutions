class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int x1=c1[0]-'a';
        int y1=c1[1]-'0';
        int x2=c2[0]-'a';
        int y2=c2[1]-'0';
        char cr1='w';
        char cr2='w';
        if((x1+y1)%2==0)cr1='b';
        if((x2+y2)%2==0)cr2='b';
        if(cr1==cr2)return true;
        else return false;

    }
};