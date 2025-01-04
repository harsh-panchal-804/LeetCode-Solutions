class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int expected=mean*(m+n);
        int real=accumulate(rolls.begin(),rolls.end(),0);
        int to_add=expected-real;
        function<vector<int>(int,int)> func=[&](int n,int to_add){
            vector<int> ans(n,to_add/n);
            vector<int> coins={6,5,4,3,2,1};
            int actual=accumulate(ans.begin(),ans.end(),0);
            int to_get=to_add-actual;
            int i=ans.size()-1;
            for(auto & a: ans){
                for(auto & coin: coins){
                    if(a+coin<=6 && coin<=to_get){
                        to_get-=coin;
                        a+=coin;
                    }
                }
            }
            for(auto i : ans){
                cout<<i<<" ";
            }
            cout<<"\n";
            return ans;
        
        };
        if(to_add<n || to_add >n*6)return {};
        else{
            vector<int> add=func(n,to_add);
            return add;
            
        }
        ///to_add is even n is even then no are to_add/n
        //// to_add is even n is odd  then no 
      
        /// 48 11 

    }
};