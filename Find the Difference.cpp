class Solution {
public:
    char findTheDifference(string s, string t) {
        int a=0;
        int b=0;
        for(auto i:s){
            a+=(int)i;
        }
        for(auto j:t){
            b+=(int) j;
        }
        return (char)b-a;
        
    }
};