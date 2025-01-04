class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(auto i :s){
            if((isalnum(i)) ){
                str+=tolower(i);
            }
        }
        string str2=str;
        reverse(str.begin(),str.end());
        cout<<str2<<endl;
        cout<<str<<endl;
        if(str==str2) return true;
        else return false;
        
    }
};