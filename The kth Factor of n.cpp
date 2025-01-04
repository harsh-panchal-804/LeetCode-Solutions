#include<cmath>
class Solution {
public:
    int kthFactor(int n, int k) {
        int lim=(int) pow(n,0.5);
        ///cout<<"lim is"<<lim<<endl;
        int count=0;
        int static ans=0;
        for(int i=1;i<n+1;i++){
            if(n%i==0){ 
                count++;
                if(count==k){   
                    ans= i;
                    break;
                }
                   
            }}

        if(count==k){
            return ans;

        }
        else{
            return -1;
        }
        
        }

};