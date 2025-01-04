class Solution {
public:
    double myPow(double x, int n) {
        double val=1;
        if(x==0) return 0;
        if(x==1) return 1;
        if(x==-1){
            if(n%2==0) return 1;
            else return -1;
        }

        if(n>0){
            if(n%2==0){
            for(long int i =0;i<n/2;i++){
                val=val*x;
            }
            val=val*val;
            ///if(val>10000 || val<-10000) return 0;
            return val;
            }
            else{
                for(long int i =0;i<n/2;i++){
                val=val*x;
            }
            val=val*val*x;
            
            return val;
                

            }
        }
        else{
            if((n%2==0)){
            for(long int i =0;i<abs(n)/2;i++){
                val=val*x;
            }
            val=val*val; 
            val=1/val;
            return val;
            }
            else{
            for(long int i =0;i<abs(n)/2;i++){
                val=val*x;
            }
            val=val*val*x; 
            val=1/val;
            return val;

            }


        }
        
    }
};