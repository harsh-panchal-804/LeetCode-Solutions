#include<vector>
#include<algorithm>
class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> vect;
        long long int revx=0;
        long long int ogx=x;

        if (x<0) {
            return false;
        }
        else if(x==0) return true;

        else{
            
        while(x!=0){
            int digit=x%10;
            vect.push_back(digit);
            x=x/10;
        }
        
        }
        reverse(vect.begin(),vect.end());
        for(int i =0;i<vect.size();i++){
            revx=revx+(vect[i]*pow(10,i));
        }
       
        
        if (revx!=ogx) {return false;}

        else {
            cout<<"here";
            return true;}
        

        
    }
};