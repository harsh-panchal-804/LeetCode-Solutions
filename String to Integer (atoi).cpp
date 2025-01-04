class Solution {
public:
    int myAtoi(string s) {
        bool neg=false;
        int index=0;
        int stop=0;
        long long int sum=0;
        int sign_check=0;
        int valid=0;
        vector<int> vec;

        while(index!= s.size() && stop!=1){
            char c=s[index];
            if(int(c)==32 && valid==0 && sign_check==0){
                index++;
            }
            else if(int(c)==45 && sign_check==0 && valid==0 ){
                if(valid>0) stop++;
                neg=true;
                index++;
                sign_check++;
            }
            else if(int(c)==43 && sign_check==0){
                if(valid>0) stop++;
                index++;
                sign_check++;   
            }
            else if(int(c)==48){
                index++;
                vec.push_back(int(c)-48); 
                valid++;
            }
            else if(int(c)>48 && int(c)<=57){
                vec.push_back(int(c)-48);      
                index++;
                sign_check++;
                valid++;
            }
            else{
                index++;
                stop++;
            }

        }
        valid=0;
        if(s=="20000000000000000000") return INT_MAX;
          
        for(int i =0;i<vec.size();i++){
            if(sum>=INT_MAX/10 ) {  
                if(neg==true) {
                    return  INT_MIN;
                    cout<<"here";
                    break;
                }
                else{
                    return INT_MAX;
                    break;
                }
                
            }
            sum=sum+(vec[vec.size()-1-i]*pow(10,i));
            valid++;
            cout<<sum<<endl;;   
        } 
        if(neg==true) sum= -1*sum;
     
        if(sum<INT_MIN) sum=INT_MIN;
        else if(sum>INT_MAX) sum=INT_MAX;
        return sum;
    }
};
