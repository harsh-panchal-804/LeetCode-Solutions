class Solution {
public:
    bool check(int n,int sum){
        //convert to string
        if(n==1) return true;
        else{
        
        while(n>4){
            string str=to_string(n);
            for(auto i : str){
                sum+=pow(i-'0',2);
            }
            cout<<sum<<endl;
            if(sum==1) return true;
            n=sum;
            sum=0;
        }
        return false;
    }
    
    }
    bool isHappy(int n) {
        return check(n,0);    
    }
};