class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0;
        for(auto i: bank[0]){
            if(i=='1'){
                prev++;
            }
        }
        
        int res=0;
        for(int i=1;i<=bank.size()-1;i++){
            int curr=0;
            for(auto i: bank[i]){
                if(i=='1') curr++;  
            }
            if(curr>0){
                res+=curr*prev;
                prev=curr;

            }
            cout<<"curr"<<curr;
            cout<<"prev"<<prev;
        }
        return res;
        
    }
};